#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <vector>

// подключаем вашу структуру данных
#include "data_structure.hpp"

using namespace std;
// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

int main() {

  const auto path = string(kDatasetPath);
  const auto output_path = string(kProjectPath) + "/benchmark/result/benchmark_result.csv";

  // работа с набором данных
  vector<string> files = {"100", "500", "1000", "5000", "10000", "50000", "100000", "500000", "1000000"};
  int a, b;
  for (string file : files) {         // Проходим по всем 9 .csv файлам
        // string line = "1";
        auto input_file = ifstream(path + "/" + "insert/" + file + ".csv");
        auto time_diff = chrono::nanoseconds::zero();
        cout << (path + "/" + "insert/" + file) << endl;
        // здесь находится участок кода, время которого необходимо замерить
        input_file >> a;
        input_file >> b;
        InitGraph g(a + 1);
        int mass[3];
        for (int i = 0; i < b; i++) {
          for (int i = 0; i < 3; ++i) {
            input_file >> mass[i];
          }
          g.addVertex(mass[0], mass[1], mass[2]);
        }
        const auto time_point_before_insert = chrono::steady_clock::now();
        Heap heap = g.prim();
        const auto time_point_after_insert = chrono::steady_clock::now();
        time_diff += time_point_after_insert - time_point_before_insert;
        const auto time_elapsed_ns_insert = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
        cout << time_elapsed_ns_insert << endl;
        input_file.close();
        heap.~Heap();
    }
  return 0;
}



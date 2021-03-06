#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Heap {
  static const int SIZE = 100; // максимальный размер кучи
  int *h;         // указатель на массив кучи
  int HeapSize;   // размер кучи


  public:
    Heap();  // конструктор кучи
    void addelem(int);  // добавление элемента кучи
    void heapify(int);  // упорядочение кучи
    ~Heap(); //диструктор кучи
};

#define edge pair<int,int>

struct InitGraph {
 private:
  vector<pair<int, edge>> G;
  vector<pair<int, edge>> T; // mst
  int *parent;
  int V;

 public:
  explicit InitGraph(int V);
  void addVertex(int index, int connectionVertex, int weight);
  int findVertex(int index);
  void unite(int index, int connectionVertex);
  Heap prim();

};
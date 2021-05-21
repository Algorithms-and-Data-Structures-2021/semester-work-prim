#include "data_structure.hpp"
#include <iostream>


Heap :: Heap() {
  h = new int[SIZE];
  HeapSize = 0;
}


void Heap :: addelem(int n) {
  int i, parent;
  i = HeapSize;
  h[i] = n;
  parent = (i-1)/2;
  while(parent >= 0 && i > 0)  {
    if(h[i] > h[parent]) {
      int temp = h[i];
      h[i] = h[parent];
      h[parent] = temp;
    }
    i = parent;
    parent = (i-1)/2;
  }
  HeapSize++;
}

void Heap:: outHeap(void) {
  int i = 0;
  int k = 1;
  while(i < HeapSize) {
    while((i < k) && (i < HeapSize)) {
      cout << h[i] << " ";
      i++;
    }
    cout << endl;
    k = k * 2 + 1;
  }
}

void Heap:: out(void) {
  for(int i=0; i< HeapSize; i++) {
    cout << h[i] << " "; }
  cout << endl;
}

void Heap:: heapify(int i) {
  int left, right;
  int temp;
  left = 2*i+1;
  right = 2*i+2;
  if(left < HeapSize) {
    if(h[i] < h[left]) {
      temp = h[i];
      h[i] = h[left];
      h[left] = temp;
      heapify(left);
    }
  }
  if(right < HeapSize) {
    if(h[i] < h[right]) {
      temp = h[i];
      h[i] = h[right];
      h[right] = temp;
      heapify(right);
    }
  }
}

InitGraph::InitGraph(int V) {
  // здесь должны быть определения методов вашей структуры
  parent = new int[V];

  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}
void InitGraph::addVertex(int index, int connectionVertex, int weight) {
  G.push_back(make_pair(weight, edge(index, connectionVertex)));
}
int InitGraph::findVertex(int index) {
  if (index == parent[index])
    return index;
  else
    return findVertex(parent[index]);
}

void InitGraph::unite(int index, int connectionVertex) {
  parent[index] = parent[connectionVertex];
}
Heap InitGraph::prim() {
  Heap heap;
  int i, uRep, vRep;
  sort(G.begin(), G.end());
  for (i = 0; i < G.size(); i++) {
    uRep = findVertex(G[i].second.first);
    vRep = findVertex(G[i].second.second);
    if (uRep != vRep) {
      heap.addelem(uRep);
      heap.addelem(vRep);
      T.push_back(G[i]);
      unite(uRep, vRep);
      heap.heapify(uRep);
      heap.heapify(vRep);
    }
  }
  return heap;
}
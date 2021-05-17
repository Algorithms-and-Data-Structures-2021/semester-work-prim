#pragma once

#include <iostream>

using namespace std;

//Edge structure
struct edge {
  int v_start;
  int v_end;
  int weight;
};

struct node {
  int key;
  int degree;
  node* parent;
  node* child;
  node* sibling;
  int i;
};

struct vertex {
  vertex() {
    visited = false;
    selected = 0;
    inHeap = 0;
    i = 0;
  }

  bool visited;
  edge* selected;
  node* inHeap;
  vector<edge*> connect;
  int i;
};
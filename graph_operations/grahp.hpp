#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Graph {
  public:
      Graph();
      Graph(vector<vector<int>> adjacency_list);
      
      void addNode(int x);
      void addEdge(int u, int v);
      void showNeighbors(int u);
      void info();

  private:
  	vector<vector<int>> adjacency_list;
};

#endif

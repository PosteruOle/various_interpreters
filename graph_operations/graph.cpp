#include <iostream>
#include "graph.hpp"

Graph::Graph() { }

Graph::Graph(vector<vector<int>> adjacency_list){
    this.adjacency_list=adjacency_list;
}
      
void Graph::addNode(int x){
    this.adjacency_list.push_back(x, vector<int>());
}

void Graph::addEdge(int u, int v){
    this.adjacency_list[u].push_back(v);
    this.adjacency_list[v].push_back(u);
}

void Graph::showNeighbors(int u){

}

void Graph::info(){
    cout << "We haven't decide yet in what format should we print the graph information!\n";
}

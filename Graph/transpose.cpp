#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > graph;

vector< vector<int> > transpose() {
  vector< vector<int> > tmp(graph.size(), vector<int> ());
  
  for(int i = 0; i < graph.size(); i++) {
    for(int j = 0; j < graph[i].size(); j++) {
      int v = graph[i][j];
      tmp[v].push_back(i);
    }
  }

  return tmp;
}

int main() {

  graph.assign(5, vector<int>());

  graph[1].push_back(0);
  graph[0].push_back(2);
  graph[2].push_back(1);
  graph[0].push_back(3);
  graph[3].push_back(4);

  vector< vector<int> > transposed = transpose();

  for(int i = 0; i < transposed.size(); i++) {
    cout << i << " -> ";
    for(int j = 0; j < transposed[i].size(); j++) {
      cout << transposed[i][j] << " ";
    }
    cout << endl;
  }

  graph.clear();
  transposed.clear();

  return 0;
}
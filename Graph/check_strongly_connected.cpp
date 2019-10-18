#include <iostream>
#include <vector>

using namespace std;

void dfs(vector< vector<int> > graph, int v, vector<bool> &seen) {
  seen[v] = true;

  for(int i = 0; i < graph[v].size(); i++) {
    int u = graph[v][i];
    if(!seen[u])
      dfs(graph, u, seen);
  }
}

bool checkStronglyConnected(vector< vector<int> > graph) {
  vector<bool> seen(graph.size(), false);

  dfs(graph, 0, seen);

  for(int i = 0; i < seen.size(); i++) {
    if(!seen[i])
      return false;
  }

  vector< vector<int> > transposed(graph.size(), vector<int>());
  for(int i = 0; i < graph.size(); i++) {
    for(int j = 0; j < graph[i].size(); j++) {
      int u = graph[i][j];
      transposed[u].push_back(i);
    }
    seen[i] = false;
  }

  dfs(transposed, 0, seen);

  for(int i = 0; i < seen.size(); i++) {
    if(!seen[i])
      return false;
  }

  return true;
}

int main() {

  vector< vector<int> > graph(5, vector<int>());

  graph[0].push_back(1);
  graph[1].push_back(2);
  graph[2].push_back(3);
  graph[3].push_back(0);
  graph[2].push_back(4);
  graph[4].push_back(2);

  if(checkStronglyConnected(graph))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  graph.clear();

  return 0;
}
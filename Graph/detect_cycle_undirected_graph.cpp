#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > graph;
vector<int> seen;

bool dfs(int v, int parent) {
  seen[v] = true;

  for(int i = 0; i < graph[v].size(); i++) {
    int u = graph[v][i];

    if(seen[u] && u != parent)
      return true;

    if(!seen[u] && dfs(u, v))
      return true;
  }

  return false;
}

bool hasCycle() {
  seen.assign(graph.size(), false);

  for(int i = 0; i < graph.size(); i++) {
    if(!seen[i])
      if(dfs(i, -1))
        return true;
  }

  return false;
}

int main() {

  graph.assign(5, vector<int>());

  graph[1].push_back(0);
  graph[0].push_back(1);
  //graph[0].push_back(2);
  //graph[2].push_back(0);
  graph[2].push_back(1);
  graph[1].push_back(2);
  graph[0].push_back(3);
  graph[3].push_back(0);
  graph[3].push_back(4);
  graph[4].push_back(3);

  if(hasCycle())
    cout << "The graph has a cycle" << endl;
  else
    cout << "There is no cycle" << endl;

  graph.clear();
  seen.clear();

  return 0;
}
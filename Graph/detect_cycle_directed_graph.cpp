#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > graph;
vector<int> seen, stack;

bool dfs(int v) {
  seen[v] = true;
  stack[v] = true;

  for(int i = 0; i < graph[v].size(); i++) {
    int u = graph[v][i];
    
    if(stack[u])
      return true;

    if(!seen[u] && dfs(u))
      return true;
  }

  stack[v] = false;
  return false;
}

bool hasCycle() {
  seen.assign(graph.size(), false);
  stack.assign(graph.size(), false);

  for(int i = 0; i < graph.size(); i++) {
    if(dfs(i))
      return true;
  }

  return false;
}

int main() {

  graph.assign(5, vector<int>());

  graph[1].push_back(0);
  //graph[0].push_back(2);
  graph[2].push_back(1);
  graph[0].push_back(3);
  graph[3].push_back(4);

  if(hasCycle())
    cout << "The graph has a cycle" << endl;
  else
    cout << "There is no cycle" << endl;

  graph.clear();
  seen.clear();
  stack.clear();

  return 0;
}
// Mother vertex is a vertex v such that all other vertices in Graph
// can be reached by a path from v.
// Complexity: O(V + E)

#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > graph;
vector<bool> seen;

void dfs(int u) {
  seen[u] = true;

  for(int i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if(!seen[v])
      dfs(v);
  }
}

int findMotherVertex() {
  int mother;

  for(int i = 0; i < graph.size(); i++) {
    if(!seen[i]) {
      dfs(i);
      mother = i;
    }
  }

  for(int i = 0; i < graph.size(); i++)
    seen[i] = false;

  dfs(mother);

  for(int i = 0; i < graph.size(); i++) {
    if(!seen[i])
      return -1;
  }

  return mother;
}

int main() {

  graph.assign(5, vector<int>());

  graph[1].push_back(0);
  graph[0].push_back(2);
  graph[2].push_back(1);
  graph[0].push_back(3);
  graph[3].push_back(4);

  seen.assign(graph.size(), false);

  int mother = findMotherVertex();
  if(mother != -1)
    cout << "Mother vertex: " << mother << endl;
  else
    cout << "There is no mother vertex" << endl;

  graph.clear();
  seen.clear();

  return 0;
}
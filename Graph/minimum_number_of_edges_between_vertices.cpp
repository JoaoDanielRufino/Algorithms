#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< vector<int> > graph;
vector<bool> seen;

int minEdges(int start, int end) {
  queue<int> q;
  vector<int> dist(graph.size(), 0);

  q.push(start);
  seen[start] = true;
  while(!q.empty()) {
    int top = q.front();
    q.pop();

    if(top == end)
      return dist[end];

    for(int i = 0; i < graph[top].size(); i++) {
      int adj = graph[top][i];
      if(!seen[adj]) {
        dist[adj] = dist[top] + 1;
        q.push(adj);
        seen[adj] = true;
      }
    }
  }

  return -1;
}

int main() {

  graph.assign(5, vector<int>());

  graph[1].push_back(0);
  graph[0].push_back(2);
  graph[2].push_back(1);
  graph[0].push_back(3);
  graph[3].push_back(4);

  seen.assign(graph.size(), false);

  int res = minEdges(0, 4);
  if(res != -1)
    cout << "Minimum number of edges: " << res << endl;
  else
    cout << "There is no path between these vertices" << endl;

  graph.clear();
  seen.clear();

  return 0;
}
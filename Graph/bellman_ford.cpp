// Complexity: O(VE)

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void addEdge(vector< pair<int, pair< int, int> > > &edges, int u, int v, int w) {
  edges.push_back(make_pair(w, make_pair(u, v)));
}

void BellmanFord(vector< pair<int, pair< int, int> > > edges, int v, int src, int end) {
  vector<int> dist(v, INT_MAX);

  dist[src] = 0;
  for(int i = 0; i < v-1; i++) {
    for(int j = 0; j < edges.size(); j++) {
      int u = edges[j].second.first;
      int v = edges[j].second.second;
      int wt = edges[j].first;
      if(dist[v] > dist[u] + wt)
        dist[v] = dist[u] + wt;
    }
  }

  for(int i = 0; i < edges.size(); i++) {
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    int wt = edges[i].first;
    if(dist[v] > dist[u] + wt) {
      cout << "Negative cycle found" << endl;
      return;
    }
  }

  cout << "Minimum distance from " << src << " to " << end << " is " << dist[end] << endl;
}

int main() {

  vector< pair<int, pair<int, int> > > edges;
  int v = 5;

  addEdge(edges, 0, 1, -1);
  addEdge(edges, 0, 2, 4);
  addEdge(edges, 1, 2, 3);
  addEdge(edges, 1, 3, 2);
  addEdge(edges, 1, 4, 2);
  addEdge(edges, 3, 2, 5);
  addEdge(edges, 3, 1, 1);
  addEdge(edges, 4, 3, -3);

  BellmanFord(edges, v, 0, 3);

  return 0;
}

// https://www.coursera.org/learn/algorithms-part2/lecture/HoHKu/prims-algorithm
// This is the lazy implementation of prims algorithm
// Complexity: O(ElogV)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> myPair;

void addEdge(vector< vector<myPair> > &graph, int v, int u, int w) {
  graph[v].push_back(make_pair(u, w));
  graph[u].push_back(make_pair(v, w));
}

class PrimsMST {
  private:
    int weight;
    vector< pair<int, myPair> > mst;
    priority_queue< pair<int, myPair>, vector< pair<int, myPair> >, greater<pair<int, myPair> > > minPQ;
    vector<bool> marked;

    void visit(vector< vector<myPair> > graph, int v) {
      marked[v] = true;

      for(int i = 0; i < graph[v].size(); i++) {
        int u = graph[v][i].first; // Adj
        int w = graph[v][i].second; // Weight
        if(!marked[u])
          minPQ.push(make_pair(w, make_pair(v, u)));
      }
    }

  public:
    PrimsMST(vector< vector<myPair> > graph) {
      marked.assign(graph.size(), false);
      weight = 0;
      
      visit(graph, 0); // Taking vertex 0 as source
      while(!minPQ.empty() && mst.size() < graph.size()-1) {
        pair<int, myPair> edge = minPQ.top();
        minPQ.pop();

        int v = edge.second.first;
        int u = edge.second.second;
        int w = edge.first;

        if(marked[v] && marked[u])
          continue;

        mst.push_back(edge);
        weight += w;
        if(!marked[v])
          visit(graph, v);
        if(!marked[u])
          visit(graph, u);
      }
    }

    void printMST() {
      for(int i = 0; i < mst.size(); i++) {
        cout << mst[i].second.first << " - " << mst[i].second.second << " with weight: " << mst[i].first << endl;
      }
      cout << "Weight of MST: " << weight << endl;
    }
};

int main() {

  vector< vector<myPair> > graph(9, vector<myPair> ());

  addEdge(graph, 0, 1, 4); 
  addEdge(graph, 0, 7, 8); 
  addEdge(graph, 1, 2, 8); 
  addEdge(graph, 1, 7, 11); 
  addEdge(graph, 2, 3, 7); 
  addEdge(graph, 2, 8, 2); 
  addEdge(graph, 2, 5, 4); 
  addEdge(graph, 3, 4, 9); 
  addEdge(graph, 3, 5, 14); 
  addEdge(graph, 4, 5, 10); 
  addEdge(graph, 5, 6, 2); 
  addEdge(graph, 6, 7, 1); 
  addEdge(graph, 6, 8, 6); 
  addEdge(graph, 7, 8, 7);

  PrimsMST mst(graph);

  mst.printMST();

  graph.clear();

  return 0;
}
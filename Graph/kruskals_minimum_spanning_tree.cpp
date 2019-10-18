// Complexity: O(ElogE + ElogV) -> ElogE to sort the edges
// We can consider O(ElogV)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
  private:
    int vertices;
    vector< pair<int, pair<int, int> > > edges; // Edge representation

  public:
    Graph(int v) {
      vertices = v;
    }

    void addEdge(int v, int u, int w) {
      edges.push_back(make_pair(w, make_pair(v, u)));
    }

    int getV() {
      return vertices;
    }

    vector< pair<int, pair<int, int> > > getEdges() {
      return edges;
    }
};

class UnionFind {
  private:
    int *vet;
    int size;

    int root(int i) {
      if(i == vet[i])
        return i;
      
      return root(vet[i]);
    }

  public:
    UnionFind(int size) {
      this->size = size;
      vet = new int[size];
      for(int i = 0; i < size; i++)
        vet[i] = i;
    }

    bool connected(int p, int q) {
      return root(p) == root(q);
    }

    void myUnion(int p, int q) {
      int i = root(p);
      int j = root(q);
      vet[i] = j;
    }
};

class KruskalMST {
  private:
    int weight;
    vector< pair<int, pair<int, int> > > mst;

  public:
    KruskalMST(Graph g) {
      vector< pair<int, pair<int, int> > > edges = g.getEdges();
      sort(edges.begin(), edges.end());

      UnionFind uf(g.getV());
      weight = 0;
      for(int i = 0; i < edges.size(); i++) {
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        int w = edges[i].first;

        if(!uf.connected(a, b)) { // If connected, this edge will create a cycle, so we check if not connected
          mst.push_back(make_pair(w, make_pair(a, b)));
          weight += w;
          uf.myUnion(a, b);
        }

        if(mst.size() >= g.getV()-1) // A MST has V-1 edges
          break;
      }
    }

    int getWeight() {
      return weight;
    }

    void printMST() {
      for(int i = 0; i < mst.size(); i++) {
        cout << mst[i].second.first << " - " << mst[i].second.second << " with weight: " << mst[i].first << endl;
      }
      cout << "Weight of MST: " << weight << endl;
    }
};

int main() {

  Graph g(9);

  g.addEdge(0, 1, 4); 
  g.addEdge(0, 7, 8); 
  g.addEdge(1, 2, 8); 
  g.addEdge(1, 7, 11); 
  g.addEdge(2, 3, 7); 
  g.addEdge(2, 8, 2); 
  g.addEdge(2, 5, 4); 
  g.addEdge(3, 4, 9); 
  g.addEdge(3, 5, 14); 
  g.addEdge(4, 5, 10); 
  g.addEdge(5, 6, 2); 
  g.addEdge(6, 7, 1); 
  g.addEdge(6, 8, 6); 
  g.addEdge(7, 8, 7);

  KruskalMST mst(g);

  mst.printMST();

  return 0;
}
// https://leetcode.com/problems/redundant-connection/

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

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size()+1);
        
        for(vector<int> edge : edges) {
            if(!uf.connected(edge[0], edge[1])) {
                uf.myUnion(edge[0], edge[1]);
            } else {
                return edge;
            }
        }
        
        return vector<int> ();
    }
};

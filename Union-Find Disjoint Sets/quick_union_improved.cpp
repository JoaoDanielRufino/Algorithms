#include <iostream>

using namespace std;

class QuickUnion {
  private:
    int *vet;
    int *rank;
    int size;

    int root(int i) {
      if(i == vet[i])
        return i;
      
      return root(vet[i]);
    }

  public:
    QuickUnion(int size) {
      this->size = size;
      vet = new int[size];
      rank = new int[size];
      for(int i = 0; i < size; i++)
        vet[i] = i;
    }

    bool connected(int p, int q) {
      return root(p) == root(q);
    }

    void myUnion(int p, int q) {
      int i = root(p);
      int j = root(q);
      
      if(rank[i] > rank[j])
        vet[j] = i;
      else if(rank[i] < rank[j])
        vet[i] = j;
      else {
        vet[i] = j;
        rank[j]++;
      }
    }
};

int main() {

  int n = 10;

  QuickUnion qu(n);

  qu.myUnion(1, 2);
  qu.myUnion(3, 5);
  qu.myUnion(7, 9);
  qu.myUnion(2, 7);

  cout << qu.connected(1, 9) << endl;
  cout << qu.connected(3, 7) << endl;

  return 0;
}
// https://www.coursera.org/learn/algorithms-part1/lecture/EcF3P/quick-find
// Find -> O(1)
// Union -> O(n)

#include <iostream>

using namespace std;

class QuickFind {
  private:
    int *vet;
    int size;

  public:
    QuickFind(int size) {
      this->size = size;
      vet = new int[size];
      for(int i = 0; i < size; i++)
        vet[i] = i;
    }

    bool connected(int p, int q) {
      return vet[p] == vet[q];
    }

    void myUnion(int p, int q) {
      int pid = vet[p];
      int qid = vet[q];
      for(int i = 0; i < size; i++) {
        if(vet[i] == pid)
          vet[i] = qid;
      }
    }
};

int main() {

  int n = 10;

  QuickFind qf(n);

  qf.myUnion(1, 2);
  qf.myUnion(3, 5);
  qf.myUnion(7, 9);
  qf.myUnion(2, 7);

  cout << qf.connected(1, 9) << endl;
  cout << qf.connected(3, 7) << endl;

  return 0;
}
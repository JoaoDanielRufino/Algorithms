/*Complexity: worst case: O(nLogn).
              best case: O(nLogn).
              */

#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &vet, int size, int root) {
  int largest = root;
  int l = 2*root + 1; // left
  int r = 2*root + 2; // right
 
  if(l < size && vet[l] > vet[largest])
    largest = l;

  if(r < size && vet[r] > vet[largest])
    largest = r;

  if(largest != root) {
    swap(vet[root], vet[largest]);
    heapify(vet, size, largest);
  }
}

void heapSort(vector<int> &vet) {
  int size = vet.size();

  for(int i = size/2 - 1; i >= 0; i--) // Building the heap
    heapify(vet, size, i);

  for(int i = size-1; i >= 0; i--) {
    swap(vet[0], vet[i]); // Swap the root with the last element
    heapify(vet, i, 0);  // Rearrange the heap without the last element
  }
}

int main() {

  vector<int> vet;

  vet.push_back(3);
  vet.push_back(9);
  vet.push_back(1);
  vet.push_back(5);
  vet.push_back(14);
  vet.push_back(2);
  vet.push_back(8);
  vet.push_back(10);

  heapSort(vet);

  for(int i = 0; i < vet.size(); i++) {
    cout << vet[i] << " ";
  }

  cout << endl;

  return 0;
}
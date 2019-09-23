#include <iostream>

using namespace std;

void myReverse(int *vet, int size) {
  int start = 0;
  int end = size - 1;

  while(start < end) {
    vet[start] ^= vet[end];
    vet[end] ^= vet[start];
    vet[start] ^= vet[end];

    start++;
    end--;
  }
}

int main() {

  int vet[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
  int size = sizeof(vet) / sizeof(vet[0]);

  myReverse(vet, size);

  for(int i = 0; i < size; i++)
    cout << vet[i] << " ";

  cout << endl;

  return 0;
}
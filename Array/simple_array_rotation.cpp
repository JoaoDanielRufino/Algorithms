#include <iostream>

using namespace std;

void rotate(int *vet, int rotations, int size) {
  if(!rotations)
    return;

  int tmp = vet[0];
  for(int i = 0; i < size-1; i++) {
    vet[i] = vet[i+1];
  }
  vet[size-1] = tmp;

  rotate(vet, rotations - 1, size);
}

int main() {

  int vet[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
  int size = sizeof(vet) / sizeof(vet[0]);

  rotate(vet, 3, size);

  for(int i = 0; i < size; i++)
    cout << vet[i] << " ";

  cout << endl;

  return 0;
}
// https://www.geeksforgeeks.org/array-rotation/

#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if(!b)
    return a;

  return gcd(b, a % b);
}

void rotate(int *vet, int rotations, int size) {
  int aux = gcd(rotations, size);

  for(int i = 0; i < aux; i++) {
    int tmp = vet[i];
    int j = i;
    int k = (j + rotations) % size;

    while(k != i) {
      vet[j] = vet[k];
      j = k;
      k = (j + rotations) % size;    
    }

    vet[j] = tmp;
  }
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
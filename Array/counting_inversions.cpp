// https://www.geeksforgeeks.org/counting-inversions/

#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& vet, int l, int mid, int r) {
  int i, j, k, inversions;
  int n1 = mid - l + 1;
  int n2 = r - mid;
  vector<int> L, R;

  for(i = 0; i < n1; i++)
    L.push_back(vet[l + i]);
  for(j = 0; j < n2; j++)
    R.push_back(vet[mid + 1 + j]);

  i = j = inversions = 0;
  k = l;
  while(i < n1 && j < n2) {
    if(L[i] <= R[j])
      vet[k] = L[i++];
    else {
      vet[k] = R[j++];
      inversions += (mid + 1) - (i + l);
    }
    k++;
  }

  while(i < n1)
    vet[k++] = L[i++];
  while(j < n2)
    vet[k++] = R[j++];

  return inversions;
}

int countInversions(vector<int>& vet, int l, int r) {
  if(l >= r)
    return 0;

  int mid = l + (r - l)/2;
  return countInversions(vet, l, mid) + countInversions(vet, mid+1, r) + merge(vet, l, mid, r);
}

int main() {

  vector<int> vet{ 5, 1, 3, 4, 2 };

  cout << countInversions(vet, 0, vet.size()-1) << endl;

  return 0;
}
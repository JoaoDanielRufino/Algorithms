/*Complexity: worst case: O(n log(n)).
              best case: O(n log(n)).
              */
#include <iostream>
#include <vector>
#include <stdlib.h>
#define N 100

using namespace std;

void merge(vector<int> &vet, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L, R;
    
    for(i = 0; i < n1; i++)
        L.push_back(vet[l + i]);
    for(j = 0; j < n2; j++)
        R.push_back(vet[m + 1 + j]);

    i = j = 0;
    k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j])
            vet[k] = L[i++];
        else
            vet[k] = R[j++];
        k++;
    }

    while(i < n1)
        vet[k++] = L[i++];
    while(j < n2)
        vet[k++] = R[j++];
}

void merge_sort(vector<int> &vet, int l, int r) {
    if(l >= r)
        return;

    int mid = (l + r) / 2;
    merge_sort(vet, l, mid);
    merge_sort(vet, mid+1, r);
    merge(vet, l, mid, r);
}

int main(){

    ios::sync_with_stdio(false);
    int n,a;
    vector<int> vet;

    cout << "input size: ";
    cin >> n;

    cout << "Random numbers:";
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        a = rand()%N;
        vet.push_back(a);
        cout << " " << a;
    }

    merge_sort(vet, 0, n-1);

    cout << endl << "Numbers sorted: ";
    for(int i = 0; i < n; i++)
        cout << vet[i] << " ";

    cout << endl;

    return 0;
}

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
    vector<int> L, R;
    
    for(i = l; i <= m; i++)
        L.push_back(vet[i]);
    for(j = m + 1; j <= r; j++)
        R.push_back(vet[j]);

    i = j = 0;
    k = l;
    while(i < L.size() && j < R.size()) {
        if(L[i] <= R[j])
            vet[k] = L[i++];
        else
            vet[k] = R[j++];
        k++;
    }

    while(i < L.size())
        vet[k++] = L[i++];
    while(j < R.size())
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

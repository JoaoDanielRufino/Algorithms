/*Complexity: worst case: O(n log(n)).
              best case: O(n log(n)).
              */
#include <bits/stdc++.h>
#define N 100

using namespace std;

void merge_sort(vector<int> &vet, int n){
    if(n <= 1)
        return;

    int m = n/2;
    vector<int> v1,v2;

    for(int i = 0; i < m; i++)
        v1.push_back(vet[i]);
    for(int i = m; i < n; i++)
        v2.push_back(vet[i]);

    merge_sort(v1, m);
    merge_sort(v2, n-m);

    int i,j;
    i = j = 0;
    for(int k = 0; k < n; k++){
        if(i >= m)
            vet[k] = v2[j++];
        else if(j >= n-m)
            vet[k] = v1[i++];
        else if(v1[i] < v2[j])
            vet[k] = v1[i++];
        else
            vet[k] = v2[j++];
    }

}

int main(){

    ios::sync_with_stdio(false);
    int n,a;
    vector<int> vet;

    cout << "input size: ";
    cin >> n;

    srand(time(NULL));
    for(int i = 0; i < n; i++){
        a = rand()%N;
        vet.push_back(a);
    }

    merge_sort(vet, n);

    cout << endl << "Numbers sorted: ";
    for(int i = 0; i < n; i++)
        cout << vet[i] << " ";

    cout << endl;

    return 0;
}

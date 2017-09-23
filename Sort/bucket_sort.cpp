/*Complexity: worst case: O(n).
              best case: O(n).
              */
#include <bits/stdc++.h>
#define N 100

using namespace std;

void bucket_sort(vector<int> &vet){
    int aux[N] = {0};
    for(int i = 0; i < vet.size(); i++)
        aux[vet[i]]++;
    int i = 0;
    for(int j = 0; j < N; j++){
        while(aux[j]--)
            vet[i++] = j;
    }
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

    bucket_sort(vet);

    cout << endl << "Numbers sorted: ";
    for(int i = 0; i < n; i++)
        cout << vet[i] << " ";

    cout << endl;

    return 0;
}

/*Complexity: worst case: O(n^2).
              best case: O(n).
              */
#include <bits/stdc++.h>

using namespace std;

void selection_sort(vector<int> &vet){
    for(int i = 0; i < vet.size()-1; i++){
        for(int j = i+1; j < vet.size(); j++){
            if(vet[i] > vet[j]){
                vet[i] = vet[i] ^ vet[j];
                vet[j] = vet[i] ^ vet[j];
                vet[i] = vet[i] ^ vet[j];
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    int n,a;
    vector<int> vet;

    cout << "input size: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Number[" << i+1 << "]: ";
        cin >> a;
        vet.push_back(a);
    }

    selection_sort(vet);

    cout << endl << "Numbers sorted: ";
    for(int i = 0; i < n; i++)
        cout << vet[i] << " ";

    cout << endl;

    return 0;
}

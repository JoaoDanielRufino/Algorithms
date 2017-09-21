/*Complexity: worst case: O(n^2).
              best case: not defined.
              */
#include <bits/stdc++.h>
#define N 100

using namespace std;

void shell_sort(vector<int> &vet){
    int aux,j;
    for(int gap = vet.size()/2; gap > 0; gap /= 2){
        for(int i = gap; i < vet.size(); i++){
            aux = vet[i];
            j = i;
            while(j >= gap && vet[j-gap] > aux){
                vet[j] = vet[j-gap];
                j -= gap;
            }
            vet[j] = aux;
        }
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

    shell_sort(vet);

    cout << endl << "Numbers sorted: ";
    for(int i = 0; i < n; i++)
        cout << vet[i] << " ";

    cout << endl;

    return 0;
}

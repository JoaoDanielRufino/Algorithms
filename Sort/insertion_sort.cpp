/*Complexity: worst case: O(n^2).
              best case: O(n).
              */
#include <bits/stdc++.h>
#define N 100

using namespace std;

void insertion_sort(vector<int> &vet){
    int j,elem;
    for(int i = 1; i < vet.size(); i++){
        elem = vet[i];
        j = i - 1;
        while(j >= 0 && vet[j] > elem)
            vet[j+1] = vet[j--];
        vet[j+1] = elem;
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

    insertion_sort(vet);

    cout << endl << "Numbers sorted: ";
    for(int i = 0; i < n; i++)
        cout << vet[i] << " ";

    cout << endl;

    return 0;
}

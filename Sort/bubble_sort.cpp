/*Complexity: worst case: O(n^2).
              best case: O(n).
              */
#include <bits/stdc++.h>
#define N 100

using namespace std;

void bubble_sort(vector<int> &vet){
    bool flag;
    for(int i = vet.size()-1; i > 0; i--){
        flag = false;
        for(int j = 0; j < i; j++){
            if(vet[j] > vet[j+1]){
                vet[j] = vet[j] ^ vet[j+1];
                vet[j+1] = vet[j] ^ vet[j+1];
                vet[j] = vet[j] ^ vet[j+1];
                flag = true;
            }
        }
        if(!flag)
            break;
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

    bubble_sort(vet);

    cout << endl << "Numbers sorted: ";
    for(int i = 0; i < n; i++)
        cout << vet[i] << " ";

    cout << endl;

    return 0;
}

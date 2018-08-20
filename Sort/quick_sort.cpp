/*Complexity: worst case: O(n^2).
              best case: O(n log(n)).
              */
#include <bits/stdc++.h>
#define N 100

using namespace std;

int partition(vector<int> &vet, int start, int end){
    int pivot,index,temp;
    pivot = vet[end];
    index = start;

    for(int i = start; i < end; i++){
       if(vet[i] <= pivot){
           temp = vet[i];
           vet[i] = vet[index];
           vet[index] = temp;
           index++;
       }
   }
   temp = vet[index];
   vet[index] = vet[end];
   vet[end] = temp;
   return index;
}

void quick_sort(vector<int> &vet, int start, int end){
    if(start >= end)
        return;

    int pivot = partition(vet, start, end);
    quick_sort(vet, start, pivot-1);
    quick_sort(vet, pivot+1, end);
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

    quick_sort(vet, 0, n-1);

    cout << endl << "Numbers sorted: ";
    for(int i = 0; i < n; i++)
        cout << vet[i] << " ";

    cout << endl;

    return 0;
}

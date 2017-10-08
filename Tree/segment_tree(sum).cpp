#include <bits/stdc++.h>
#define N 100

using namespace std;

void update_st(int *st, int left, int right, int i, int dif, int index){
    if(i < left || i > right)
        return;

    int mid = left + (right - left)/2;
    st[index] += dif;
    if(left != right){
        update_st(st, left, mid, i, dif, index*2+1);
        update_st(st, mid+1, right, i, dif, index*2+2);
    }
}

void update_value(int *vet, int *st, int n, int i, int data){
    int dif = data - vet[i];
    vet[i] = data;
    update_st(st, 0, n-1, i, dif, 0);
}

int get_sum(int *st, int left, int right, int qs, int qe, int index){
    int mid = left + (right - left)/2;
    if(qs <= left && qe >= right)
        return st[index];

    if(right < qs || left > qe)
        return 0;

    return get_sum(st, left, mid, qs, qe, index*2+1) +
           get_sum(st, mid+1, right, qs, qe, index*2+2);
}

int sum(int *st, int n, int qs, int qe){
    return get_sum(st, 0, n-1, qs, qe, 0);
}

int make_st(int *vet, int left, int right, int *st, int index){
    int mid = left + (right - left)/2;

    if(left == right){
        st[index] = vet[left];
        return vet[left];
    }

    st[index] = make_st(vet, left, mid, st, index*2+1) +
                make_st(vet, mid+1, right, st, index*2+2);

    return st[index];
}

int *initiate_st(int *vet, int size){
    int x = (int) (ceil(log2(size)));
    int max_size = 2 * (int) pow(2, x) - 1;
    int *st = new int[max_size];

    make_st(vet, 0, size-1, st, 0);

    return st;
}

int main(){

    ios::sync_with_stdio(false);
    int *st,*vet,n,a,b;

    cout << "input size: ";
    cin >> n;
    vet = new int[n];

    cout << "Random numbers: ";
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        vet[i] = rand()%N;
        cout << " " << vet[i];
    }

    st = initiate_st(vet,n);

    cout << endl << endl << "Range [Ai-Aj]: ";
    cin >> a >> b;
    cout << "Sum of values [" << a << "-" << b << "]" << " = " << sum(st, n, a, b) << endl;

    cout << "Update a value [pos-value]: ";
    cin >> a >> b;
    update_value(vet, st, n, a, b);

    cout << "New range [Ai-Aj]: ";
    cin >> a >> b;
    cout << "Sum of updated values [" << a << "-" << b << "]" << " = " << sum(st, n, a, b) << endl;

    return 0;
}

#include <bits/stdc++.h>
#define N 100

using namespace std;

void update_st(int *st, int left, int right, int i, int data, int index){
    if(i < left || i > right)
        return;

    int mid = left + (right - left)/2;
    st[index] = data;
    if(left != right){
        update_st(st, left, mid, i, data, index*2+1);
        update_st(st, mid+1, right, i, data, index*2+2);
    }
}

void update_value(int *vet, int *st, int n, int i, int data){
    vet[i] = data;
    update_st(st, 0, n-1, i, data, 0);
}

int get_max(int *st, int left, int right, int qs, int qe, int index){
    int mid = left + (right - left)/2;
    if(qs <= left && qe >= right)
        return st[index];

    if(right < qs || left > qe)
        return -10101010;

    return max(get_max(st, left, mid, qs, qe, index*2+1),
           get_max(st, mid+1, right, qs, qe, index*2+2));
}

int max_value(int *st, int n, int qs, int qe){
    return get_max(st, 0, n-1, qs, qe, 0);
}

int make_st(int *vet, int left, int right, int *st, int index){
    int mid = left + (right - left)/2;

    if(left == right){
        st[index] = vet[left];
        return vet[left];
    }

    st[index] = max(make_st(vet, left, mid, st, index*2+1),
                make_st(vet, mid+1, right, st, index*2+2));

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
    cout << "Max value of [" << a << "-" << b << "]" << " = " << max_value(st, n, a, b) << endl;

    cout << "Update a value [pos-value]: ";
    cin >> a >> b;
    update_value(vet, st, n, a, b);

    cout << "New range [Ai-Aj]: ";
    cin >> a >> b;
    cout << "Max value of [" << a << "-" << b << "]" << " = " << max_value(st, n, a, b) << endl;

    return 0;
}

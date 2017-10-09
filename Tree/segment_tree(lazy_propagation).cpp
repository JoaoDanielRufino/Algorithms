#include <bits/stdc++.h>
#define MAX 10000
#define N 100

using namespace std;

int tree[MAX];
int lazy[MAX];

void update(int index, int left, int right, int us, int ue, int diff){
	if(lazy[index] != 0){
		tree[index] += (right - left+1)*lazy[index];
		if(left != right){
			lazy[index*2+1] += lazy[index];
            lazy[index*2+2] += lazy[index];
		}
		lazy[index] = 0;
	}

	if(left > right || left > ue || right < us)
		return;

	if(left >= us && right <= ue){
		tree[index] += (right - left+1)*diff;
		if(left != right){
			lazy[index*2+1] += diff;
            lazy[index*2+2] += diff;
		}
		return;
	}

	int mid = (left + right)/2;
	update(index*2+1, left, mid, us, ue, diff);
	update(index*2+2, mid+1, right, us, ue, diff);

	tree[index] = tree[index*2+1] + tree[index*2+2];
}

void update_range(int n, int us, int ue, int diff){
	update(0, 0, n-1, us, ue, diff);
}

int get_sum(int left, int right, int qs, int qe, int index){
	if(lazy[index] != 0){
		tree[index] += (right - left+1)*lazy[index];
		if(left != right){
			lazy[index*2+1] += lazy[index];
            lazy[index*2+2] += lazy[index];
		}
		lazy[index] = 0;
	}

	if(left > right || left > qe || right < qs)
		return 0;

	if(left >= qs && right <= qe)
		return tree[index];

	int mid = (left + right)/2;
	return get_sum(left, mid, qs, qe, index*2+1) +
		   get_sum(mid+1, right, qs, qe, index*2+2);
}

int sum(int n, int qs, int qe){
	return get_sum(0, n-1, qs, qe, 0);
}

void contruct(int *vet, int left, int right, int index){
	if(left > right)
		return;

	if(left == right){
		tree[index] = vet[left];
		return;
	}

	int mid = (left + right)/2;
	contruct(vet, left, mid, index*2+1);
	contruct(vet, mid+1, right, index*2+2);

	tree[index] = tree[index*2+1] + tree[index*2+2];
}

void initiate_st(int *vet, int n){
	contruct(vet, 0, n-1, 0);
}

int main(){

    	ios::sync_with_stdio(false);
    	int n,a,b,v,*vet;

	cout << "input size: ";
    	cin >> n;
    	vet = new int[n];

	cout << "Random numbers: ";
	srand(time(NULL));
	for(int i = 0; i < n; i++){
		vet[i] = rand()%N;
		cout << " " << vet[i];
	}
	for(int i = 0; i < MAX; i++)
		tree[i] = lazy[i] = 0;
	initiate_st(vet, n);

	cout << endl << endl << "Range [Ai-Aj]: ";
    	cin >> a >> b;
    	cout << "Sum of values [" << a << "-" << b << "]" << " = " << sum(n, a, b) << endl;

    	cout << "Update a value in range [Ai-Aj-value]: ";
    	cin >> a >> b >> v;
    	update_range(n, a, b, v);

    	cout << "New range [Ai-Aj]: ";
    	cin >> a >> b;
    	cout << "Sum of updated values [" << a << "-" << b << "]" << " = " << sum(n, a, b) << endl;

	cout << endl;
    return 0;
}

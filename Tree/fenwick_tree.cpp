#include <bits/stdc++.h>
#define N 100

using namespace std;

int sum(int *tree, int index){
	int sum = 0;
	index++;

	while(index > 0){
		sum += tree[index];
		index = index - (index & -index);
	}
	return sum;
}

void update(int *tree, int n, int index, int data){
	index++;
	while(index <= n){
		tree[index] += data;
		index = index + (index & -index);
	}
}

int* construct(vector<int> vet, int n){
	int *tree = new int[n+1];

	for(int i = 1; i <= n; i++)
		tree[i] = 0;

	for(int i = 0; i < n; i++)
		update(tree, n, i, vet[i]);

	return tree;
}

int main(){

	ios::sync_with_stdio(false);
    	int n,a,*tree,v;
	vector<int> vet;

	cout << "input size: ";
    	cin >> n;
	tree = new int[n+1];

	cout << "Random numbers: ";
	srand(time(NULL));
	for(int i = 0; i < n; i++){
      		a = rand()%N;
      		vet.push_back(a);
      		cout << " " << a;
	}

	tree = construct(vet, n);

	cout << endl << endl << "Index for the sum: ";
    	cin >> a;
    	cout << "Sum of values [0-" << a << "]" << " = " << sum(tree, a) << endl;

    	cout << "Update a value [index-value]: ";
    	cin >> a >> v;
    	update(tree, n, a, v);

    	cout << "New index for the sum: ";
    	cin >> a;
    	cout << "Sum of updated values [0-" << a << "]" << " = " << sum(tree, a) << endl;

	cout << endl;

    return 0;
}

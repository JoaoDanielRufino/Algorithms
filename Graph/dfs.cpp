// Complexity: O(V + E)

#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > vet;
vector<bool> seen;

void dfs(int u){
    seen[u] = true;

    cout << u << " -> ";

    for(int i = 0; i < vet[u].size(); i++){
        int v = vet[u][i];
        if(!seen[v])
            dfs(v);
    }
}

int main(){

    ios::sync_with_stdio(false);
    int n,m,a,b;

    cout << "Enter with the number of vertices: ";
    cin >> n;

    cout << "Enter with the number of edges: ";
    cin >> m;

    vet.assign(n, vector<int> ());
    seen.assign(n, false);

    cout << "Enter the edges: " << endl;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        vet[a].push_back(b);
        vet[b].push_back(a);
    }

    cout << "DFS order: ";

    //Checking disconected components
    for(int i = 0; i < n; i++){
        if(!seen[i])
            dfs(i);
    }

    cout << endl;
    vet.clear();
    seen.clear();

    return 0;
}

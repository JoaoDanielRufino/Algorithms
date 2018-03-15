#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > vet;
vector<int> seen;

void bfs(int u){
    queue<int> q;

    seen[u] = true;
    q.push(u);
    while(!q.empty()){
        int v = q.front();
        q.pop();

        cout << v << " -> ";

        for(int i = 0; i < vet[v].size(); i++){
            int tmp = vet[v][i];
            if(!seen[tmp]){
                seen[tmp] = true;
                q.push(tmp);
            }
        }
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

    cout << "Enter with V and E: " << endl;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        vet[a].push_back(b);
        vet[b].push_back(a);
    }

    cout << "BFS order: ";

    //Checking disconected components
    for(int i = 0; i < n; i++){
        if(!seen[i])
            bfs(i);
    }

    cout << endl;
    vet.clear();
    seen.clear();

    return 0;
}

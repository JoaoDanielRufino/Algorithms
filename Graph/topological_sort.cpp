#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > vet;
vector<int> seen;
stack<int> st;

void dfs(int u){
    seen[u] = true;

    for(int i = 0; i < vet[u].size(); i++){
        int v = vet[u][i];
        if(!seen[v])
            dfs(v);
    }
    st.push(u);
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
    }

    for(int i = 0; i < n; i++){
        if(!seen[i])
            dfs(i);
    }

    cout << "Topological sort: ";
    bool flag = false;
    while(!st.empty()){
        if(!flag){
            cout << st.top();
            flag = true;
        }
        else
            cout << " " << st.top();
        st.pop();
    }

    cout << endl;
    vet.clear();
    seen.clear();

    return 0;
}

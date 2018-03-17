//Check if the *undirected* graph has an eulerian path or cycle
#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > vet;
vector<bool> seen;

void dfs(int u){
    seen[u] = true;

    for(int i = 0; i < vet[u].size(); i++){
        int v = vet[u][i];
        if(!seen[v])
            dfs(v);
    }
}

//Function to check if all non-zero degree vertices are connected
bool isConected(){
    //Finding non-zero degree vertex
    int tmp = -1;
    for(int i = 0; i < vet.size(); i++){
        if(vet[i].size() != 0){
            tmp = i;
            break;
        }
    }

    if(tmp == -1)
        return true;

    dfs(tmp);

    //Checking if all non-zero degree vertices are visited
    for(int i = 0; i < vet.size(); i++){
        if(!seen[i] && vet[i].size() != 0)
            return false;
    }

    return true;
}

int isEulerian(){
    if(!isConected())
        return 0;

    int odd = 0;
    for(int i = 0; i < vet.size(); i++){
        if(vet[i].size() & 1) //That's the same as (vet[i].size() % 2) != 0
            odd++;
    }

    if(odd > 2)
        return 0;

    //Semi-eulerian(eulerian path)
    if(odd == 2)
        return 1;

    //Eulerian(eulerian cycle)
    if(!odd)
        return 2;
}

int main(){

    ios::sync_with_stdio(false); //cin.tie(0);
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

    int tmp = isEulerian();
    if(!tmp)
        cout << "The graph is not eulerian";
    else if(tmp == 1)
        cout << "There is an eulerian path";
    else
        cout << "There is an eulerian cycle";

    cout << endl;
    vet.clear();
    seen.clear();

    return 0;
}

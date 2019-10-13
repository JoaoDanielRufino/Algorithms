#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > vet;
vector<int> parent,low_time,discovery_time;
vector<bool> seen;

void find_bridges(vector< pair<int,int> > &bridges, int u, int my_time){
    seen[u] = true;
    low_time[u] = my_time;
    discovery_time[u] = my_time;

    for(int i = 0; i < vet[u].size(); i++){
        //Current adj of u
        int current = vet[u][i];

        if(!seen[current]){
            parent[current] = u;
            find_bridges(bridges, current, my_time+1);

            low_time[u] = min(low_time[u], low_time[current]);

            if(low_time[current] > discovery_time[u])
                bridges.push_back(make_pair(u, current));
        }

        else if(current != parent[u])
            low_time[u] = min(low_time[u], discovery_time[current]);
    }
}

int main(){

    ios::sync_with_stdio(false);
    int n,m,a,b;
    vector< pair<int,int> > bridges;

    cout << "Enter with the number of vertices: ";
    cin >> n;

    cout << "Enter with the number of edges: ";
    cin >> m;

    vet.assign(n, vector<int> ());
    seen.assign(n, false);
    parent.assign(n, -1);
    low_time.assign(n, 0);
    discovery_time.assign(n, 0);

    cout << "Enter the edges: " << endl;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        vet[a].push_back(b);
        vet[b].push_back(a);
    }

    //It can start from any vertex. I'm  choosing for example the vertex 0
    find_bridges(bridges, 0, 1);

    cout << endl << bridges.size() << " bridge(s): " << endl;
    for(int i = 0; i < bridges.size(); i++){
        cout << bridges[i].first << " - " << bridges[i].second << endl;
    }

    cout << endl;
    vet.clear();
    bridges.clear();
    seen.clear();
    parent.clear();
    low_time.clear();
    discovery_time.clear();

    return 0;
}

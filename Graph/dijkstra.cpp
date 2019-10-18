// Complexity: O(ElogV)

#include <bits/stdc++.h>

using namespace std;

vector< vector <pair<int,int> > > vet;
vector<int> dist;
int *path;

void show_path(int init, int end){
   if(init == end)
      cout << init;
   else if(path[end] == -1)
      cout << "There is no path between " << init << " and " << end << endl;
   else{
      show_path(init, path[end]);
      cout << " " << end;
   }
}

void dijkstra(int x, int y, int n){
   dist.assign(n, INT_MAX);
   path = (int*) malloc(n*sizeof(int));

   priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

   dist[x] = 0;
   pq.push(make_pair(0, x));
   while(!pq.empty()){
      int u = pq.top().second;
      pq.pop();

      if(u == y)
         break;

      for(int i = 0; i < vet[u].size(); i++){
         int v = vet[u][i].first;
         int wt = vet[u][i].second;
         if(dist[v] > dist[u] + wt){
            dist[v] = dist[u] + wt;
            path[v] = u;
            pq.push(make_pair(dist[v], v));
         }
      }
   }
   cout << "Shortest weight between " << x << " and " << y << ": " << dist[y] << endl;
   cout << "Shortest path: ";
   show_path(x, y);
}

int main(){

    ios::sync_with_stdio(false); //cin.tie(0);
    int n,m,a,b,w,x,y;

    cout << "Enter with the number of vertices: ";
    cin >> n;

    cout << "Enter with the number of edges: ";
    cin >> m;

    vet.assign(n, vector<pair<int,int> > ());

    cout << "Enter with edge and weight: " << endl;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        vet[a].push_back(make_pair(b, w));
        vet[b].push_back(make_pair(a, w));
    }

    cout << "Enter with first point and last point: ";
    cin >> x >> y;

    dijkstra(x, y, n);

    cout << endl;
    vet.clear();
    dist.clear();
    free(path);

    return 0;
}

//This is an exercise of flood fill present in Uva - uHunt - 11953
#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
char m[120][120];
bool seen[120][120];

bool valid(int x, int y, int n){
   if(x < 0 || x >= n)
      return false;
   if(y < 0 || y >= n)
      return false;
   if(seen[x][y] || m[x][y] == '.')
      return false;
   return true;
}

void dfs(int x, int y, int n){
   seen[x][y] = true;

   for(int i = 0; i < 4; i++){
      if(valid(x+dx[i], y+dy[i], n))
         dfs(x+dx[i], y+dy[i], n);
     }
}

int main(){

    ios::sync_with_stdio(false); cin.tie(0);
    int t,n,ship;
    char c;

    cin >> t;

    for(int k = 1; k <= t; k++){
      cin >> n;
      for(int i = 0; i < n; i++){
         for(int j = 0; j  < n; j++){
            seen[i][j] = false;
            cin >> m[i][j];
         }
      }
      ship = 0;
      for(int i = 0; i < n; i++){
         for(int j = 0; j < n; j++){
            if(!seen[i][j] && m[i][j] == 'x'){
               dfs(i, j, n);
               ship++;
            }
         }
      }
      cout << "Case " << k << ": " << ship << endl;
   }

   return 0;
}

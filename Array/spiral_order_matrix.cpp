#include <iostream>
#include <vector>

#define N 4
#define M 4

using namespace std;

void solve(int mat[N][M]) {
  int i, iEnd, j, jEnd;

  i = j = 0;
  iEnd = N - 1;
  jEnd = M - 1;
  while(i <= iEnd && j <= jEnd) {
    for(int k = j; k <= jEnd; k++) // First row
      cout << mat[i][k] << " "; 
    i++;

    for(int k = i; k <= iEnd; k++) // Last column
      cout << mat[k][jEnd] << " ";
    jEnd--;

    if(i <= iEnd) { // Last row
      for(int k = jEnd; k >= j; k--)
        cout << mat[iEnd][k] << " ";
      iEnd--;
    }

    if(j <= jEnd) { // First column
      for(int k = iEnd; k >= i; k--)
        cout << mat[k][j] << " ";
      j++;
    }
  }
}

int main() {
  int mat[N][M] = {{0, 1, 2, 3},
                  {4, 5, 6, 7},
                  {8, 9, 10, 11},
                  {12, 13, 14, 15}};

  solve(mat);

  cout << endl;

  return 0;
}
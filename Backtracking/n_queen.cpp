#include <bits/stdc++.h>
#define N 4

using namespace std;

void res(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << " " << mat[i][j] << " ";
        cout << endl;
    }
}

bool OK(int mat[N][N], int row, int col) {
    int i, j;

    for (i = 0; i < col; i++)
        if (mat[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (mat[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (mat[i][j])
            return false;

    return true;
}

bool solve(int mat[N][N], int col) {

    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (OK(mat, i, col)) {
            mat[i][col] = 1;
            if (solve(mat, col + 1))
                return true;
            mat[i][col] = 0; //Backtracking
        }
    }

    return false;
}

int main() {
    int mat[N][N] = {{0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0}};

    if (solve(mat, 0) == false) {
        cout << "Solution does not exist" << endl;
    }

    res(mat);

    return 0;
}

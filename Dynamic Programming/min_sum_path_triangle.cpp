// https://www.interviewbit.com/problems/min-sum-path-in-triangle/

int solve(vector<vector<int> > &A, int i, int j, vector< vector<int> > &dp) {
    if(i >= A.size() || j >= A[i].size())
        return 101010;
        
    if(i == A.size()-1)
        return A[i][j];
        
    if(dp[i][j] != -1)
        return dp[i][j];
        
    return dp[i][j] = A[i][j] + min(solve(A, i + 1, j, dp), solve(A, i + 1, j + 1, dp));
}

int Solution::minimumTotal(vector<vector<int> > &A) {
    vector< vector<int> > dp(A.size(), vector<int>(A.size(), -1));
    
    return solve(A, 0, 0, dp);
}

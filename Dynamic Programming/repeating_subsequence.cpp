// https://www.interviewbit.com/problems/repeating-subsequence/

int dp[110][110];

int solve(string A, string B, int i, int j) {
    if(i >= A.size() || j >= B.size())
        return 0;
        
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(A[i] == B[j] && i != j)
        return dp[i][j] = 1 + solve(A, B, i+1, j+1);
        
    return dp[i][j] = max(solve(A, B, i+1, j), solve(A, B, i, j+1));
}

int Solution::anytwo(string A) {
    memset(dp, -1, sizeof(dp));
    
    return solve(A, A, 0, 0) >= 2;
}

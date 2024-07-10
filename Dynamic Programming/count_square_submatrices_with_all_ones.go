// https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

func min(a, b int) int {
    if a < b {
        return a
    }

    return b
}

func solve(matrix [][]int, i, j int, dp [][]int) int {
    if i >= len(matrix) || j >= len(matrix[i]) {
        return 0
    }

    if matrix[i][j] == 0 {
        return 0
    }

    if dp[i][j] != -1 {
        return dp[i][j]
    }

    dp[i][j] = 1 + min(solve(matrix, i + 1, j, dp), min(solve(matrix, i, j + 1, dp), solve(matrix, i + 1, j + 1, dp)))

    return dp[i][j] 
}

func countSquares(matrix [][]int) int {
    dp := make([][]int, len(matrix))

    for i := range dp {
        dp[i] = make([]int, len(matrix[i]))
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }

    ans := 0
    for i := range matrix {
        for j := range matrix[i] {
            ans += solve(matrix, i, j, dp)
        }
    }

    return ans 
}

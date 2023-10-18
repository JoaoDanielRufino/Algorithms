// https://leetcode.com/problems/integer-break/description/

func max(a, b int) int {
    if a < b {
        return b
    }

    return a
}

type Pair struct {
    a int
    b int
}

func solve(n int, sum int, curr int, dp map[Pair]int) int {
    if sum > n || curr >= n {
        return 0
    }

    if sum == n {
        return 1
    }

    pair := Pair{
        sum,
        curr,
    }

    if value, ok := dp[pair]; ok {
        return value
    }

    dp[pair] = max(curr * solve(n, sum + curr, curr, dp), solve(n, sum, curr + 1, dp))

    return dp[pair]
}

func integerBreak(n int) int {
    dp := map[Pair]int{}
    return solve(n, 0, 1, dp) 
}

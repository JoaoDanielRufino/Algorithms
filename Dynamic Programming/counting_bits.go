// https://leetcode.com/problems/counting-bits/description

func count(n int, dp map[int]int) int {
    if n == 0 {
        return 0
    }

    if n == 1 {
        return 1
    }

    if val, ok := dp[n]; ok {
        return val
    }

    if n % 2 == 0 {
        dp[n] = count(n / 2, dp)
        return dp[n]
    }

    dp[n] = 1 + count(n / 2, dp)
    return dp[n]
}

func countBits(n int) []int {
    ans := []int{}    
    dp := map[int]int{}

    for i := 0; i <= n; i++ {
        ans = append(ans, count(i, dp))
    }

    return ans
}

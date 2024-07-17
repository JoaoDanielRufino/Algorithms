// https://leetcode.com/problems/dice-roll-simulation/description/

const mod = 1000000007

func solve(n int, rollMax []int, prev, prevFreq int, dp map[string]int) int {
    if n == 0 {
        return 1
    }

    key := fmt.Sprintf("%d_%d_%d", n, prev, prevFreq)

    if val, ok := dp[key]; ok {
        return val
    }
    
    ans := 0
    for i := 0; i < 6; i++ {
        if i == prev {
            if prevFreq < rollMax[i] {
                ans = (ans + solve(n-1, rollMax, i, prevFreq+1, dp)) % mod
            }
        } else {
            ans = (ans + solve(n-1, rollMax, i, 1, dp)) % mod
        }
    }

    dp[key] = ans
    
    return ans
}

func dieSimulator(n int, rollMax []int) int {
    dp := map[string]int{}

    return solve(n, rollMax, -1, 0, dp)
}

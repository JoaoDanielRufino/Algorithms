// https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description

type Pair struct {
    a, b int
}

var possibleSteps = []int{1, -1, 0}
var dp map[Pair]int
const mod = 1000000007

func canMove(arrLen, step int) bool {
    if step >= 0 && step < arrLen {
        return true
    }

    return false
}

func solve(steps, arrLen, currStep int) int {
    if steps == 0 {
        if currStep == 0 {
            return 1
        }
        return 0
    }

    pair := Pair{
        steps,
        currStep,
    }

    if val, ok := dp[pair]; ok {
        return val
    }

    ans := 0
    for _, step := range possibleSteps {
        nextStep := currStep + step
        if canMove(arrLen, nextStep) {
            ans = (ans + (solve(steps - 1, arrLen, nextStep)) % mod) % mod
        }
    }
    
    dp[pair] = ans

    return ans
}

func numWays(steps int, arrLen int) int {
    dp = make(map[Pair]int)
    return solve(steps, arrLen, 0)
}

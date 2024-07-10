// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/

func min(a, b int) int {
    if a < b {
        return a
    }
    
    return b
}

func max(a, b int) int {
    if a < b {
        return b
    }
    
    return a
}

func minCost(colors string, neededTime []int) int {
    ans, prevNotRemovedCost := 0, neededTime[0]
    
    for i := 1; i < len(colors); i++ {
        if colors[i] == colors[i-1] {
            ans += min(prevNotRemovedCost, neededTime[i])
            prevNotRemovedCost = max(prevNotRemovedCost, neededTime[i]) 
        } else {
            prevNotRemovedCost = neededTime[i]
        }
    }
    
    return ans
}

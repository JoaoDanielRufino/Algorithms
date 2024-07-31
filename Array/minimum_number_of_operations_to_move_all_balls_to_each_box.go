// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/

func minOperations(boxes string) []int {
    prefix, suffix := make([]int, len(boxes)), make([]int, len(boxes))
    onesCount := 0
    
    if boxes[0] == '1' {
        onesCount++
    }
    
    prefix[0] = 0
    for i := 1; i < len(boxes); i++ {
        prefix[i] = prefix[i-1] + onesCount
        if boxes[i] == '1' {
            onesCount++
        }
    }
    
    onesCount = 0 
    
    if boxes[len(boxes)-1] == '1' {
        onesCount++
    }
    
    suffix[len(boxes)-1] = 0
    for i := len(boxes)-2; i >= 0; i-- {
        suffix[i] = suffix[i+1] + onesCount
        if boxes[i] == '1' {
            onesCount++
        }
    }
    
    ans := []int{}
    for i := range prefix {
        ans = append(ans, prefix[i] + suffix[i])
    }
    
    return ans
}

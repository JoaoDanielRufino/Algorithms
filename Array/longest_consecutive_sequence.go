// https://leetcode.com/problems/longest-consecutive-sequence

func max(a, b int) int {
    if a < b {
        return b
    }

    return a
}

func longestConsecutive(nums []int) int {
    seen := map[int]bool{}

    for _, num := range nums {
        seen[num] = true
    }

    ans := 0
    for _, num := range nums {
        if !seen[num-1] {
            size := 1
            for seen[num + size] {
                size++
            }
            ans = max(ans, size)
        }
    }

    return ans
}

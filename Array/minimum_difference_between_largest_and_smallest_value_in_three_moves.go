// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description

func min(a, b int) int {
    if a < b {
        return a
    }

    return b
}

func minDifference(nums []int) int {
    if len(nums) <= 4 {
        return 0
    }

    sort.Ints(nums)

    ans, last := math.MaxInt, len(nums)-1

    ans = min(ans, nums[last-3] - nums[0])
    ans = min(ans, nums[last-2] - nums[1])
    ans = min(ans, nums[last-1] - nums[2])
    ans = min(ans, nums[last] - nums[3])

    return ans
}

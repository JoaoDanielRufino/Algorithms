// https://leetcode.com/problems/largest-divisible-subset/description/

func canAdd(nums []int, x int) bool {
    if len(nums) == 0 {
        return true
    }

    lastPos := len(nums)-1

    return nums[lastPos] % x == 0 || x % nums[lastPos] == 0
}

func solve(nums []int, i int, curr []int, subset *[]int, dp []int) {
    if i >= len(nums) {
        if len(curr) > len(*subset) {
            tmp := make([]int, len(curr))
            copy(tmp, curr)
            *subset = tmp
        }
        return
    }
    
    if canAdd(curr, nums[i]) && len(curr)+1 > dp[i] {
        dp[i] = len(curr)+1
        solve(nums, i + 1, append(curr, nums[i]), subset, dp)
    }

    solve(nums, i + 1, curr, subset, dp)
}

func largestDivisibleSubset(nums []int) []int {
    subset := []int{}    
    dp := make([]int, len(nums))

    sort.Ints(nums)
    
    solve(nums, 0, []int{}, &subset, dp)
    
    return subset
}

// or with for loop
func canAdd(nums []int, x int) bool {
    if len(nums) == 0 {
        return true
    }

    lastPos := len(nums)-1

    return nums[lastPos] % x == 0 || x % nums[lastPos] == 0
}

func solve(nums []int, start int, curr []int, subset *[]int, dp []int) {
    if len(curr) > len(*subset) {
        tmp := make([]int, len(curr))
        copy(tmp, curr)
        *subset = tmp
    }
    
    for i := start; i < len(nums); i++ {
        if canAdd(curr, nums[i]) && len(curr)+1 > dp[i] {
            dp[i] = len(curr)+1
            solve(nums, i + 1, append(curr, nums[i]), subset, dp)
        }
    }
}

func largestDivisibleSubset(nums []int) []int {
    subset := []int{}    
    dp := make([]int, len(nums))

    sort.Ints(nums)
    
    solve(nums, 0, []int{}, &subset, dp)
    
    return subset
}

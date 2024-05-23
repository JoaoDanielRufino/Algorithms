// https://leetcode.com/problems/the-number-of-beautiful-subsets/description

func solve(nums []int, k int, subset map[int]int, i int) int {
    if i >= len(nums) {
        return 0
    }

    ans := solve(nums, k, subset, i + 1)

    diff := nums[i] - k
    sum := nums[i] + k
    if subset[diff] == 0 && subset[sum] == 0 {
        subset[nums[i]]++
        ans += 1 + solve(nums, k, subset, i + 1)
        subset[nums[i]]--
    }

    return ans
}

func beautifulSubsets(nums []int, k int) int {
    return solve(nums, k, map[int]int{}, 0)
}

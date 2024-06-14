// https://leetcode.com/problems/minimum-increment-to-make-array-unique/description

func minIncrementForUnique(nums []int) int {
    sort.Ints(nums)

    ans := 0
    for i := 1; i < len(nums); i++ {
        if nums[i] <= nums[i-1] {
            ans += (nums[i-1] - nums[i]) + 1
            nums[i] = nums[i-1] + 1
        }
    }

    return ans
}

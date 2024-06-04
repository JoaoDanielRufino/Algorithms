// https://leetcode.com/problems/two-sum/description

// a + b = target -> a = target - b
func twoSum(nums []int, target int) []int {
    seen := map[int]int{}
    ans := []int{}

    for i, num := range nums {
        diff := target - num
        if val, ok := seen[diff]; ok {
            ans = []int{val, i}
            break
        }
        seen[num] = i
    }

    return ans
}

// https://leetcode.com/problems/sort-array-by-increasing-frequency/description/

func frequencySort(nums []int) []int {
    count := map[int]int{}

    for _, num := range nums {
        count[num]++
    }

    sort.Slice(nums, func(i, j int) bool {
        if count[nums[i]] == count[nums[j]] {
            return nums[i] > nums[j]
        }

        return count[nums[i]] < count[nums[j]]
    })

    return nums
}

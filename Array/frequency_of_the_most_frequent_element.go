// https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/

func max(a, b int) int {
    if a < b {
        return b
    }

    return a
}

func maxFrequency(nums []int, k int) int {
    start, ans, currSum := 0, 0, 0

    sort.Ints(nums)

    for i := range nums {
        currSum += nums[i]

        // nums[i] = target to create freq
        // (i-start+1) = number of equal freq
        // e.g. nums[i] = 12 & window size is 4, then sum should be 4 * 12 = 48
        // but the original sum might be (3 + 6 + 7 + 12) = 28
        // so we require 48 - 28 = 20 operations
        for (i - start + 1) * nums[i] - currSum > k {
            currSum -= nums[start]
            start++
        } 

        ans = max(ans, i - start + 1)
    }

    return ans
}

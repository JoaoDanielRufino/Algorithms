// https://leetcode.com/problems/binary-subarrays-with-sum/description/

func numSubarraysWithSum(nums []int, goal int) int {
    ans, currSum := 0, 0
    freq := map[int]int{}

    for _, num := range nums {
        currSum += num

        if currSum == goal {
            ans++
        }

        if val, ok := freq[currSum - goal]; ok {
            ans += val
        }

        freq[currSum]++
    }

    return ans
}

// using sliding window
func slidingWindowAtMost(nums []int, goal int) int {
    count, currSum, start := 0, 0, 0

    for i := range nums {
        currSum += nums[i]

        for start <= i && currSum > goal {
            currSum -= nums[start]
            start++
        }

        count += (i - start) + 1
    }

    return count
}

func numSubarraysWithSum(nums []int, goal int) int {
    return slidingWindowAtMost(nums, goal) - slidingWindowAtMost(nums, goal-1)
}

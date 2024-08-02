// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description

func min(a, b int) int {
    if a < b {
        return a
    }

    return b
}

func minSwaps(nums []int) int {
    totalOnes := 0

    for _, num := range nums {
        totalOnes += num
    } 

    if totalOnes == 0 || totalOnes == len(nums) {
        return 0
    }

    l, r, onesCount := 0, 0, 0
    for r < totalOnes {
        if nums[r] == 1 {
            onesCount++
        }
        r++
    }

    ans := min(math.MaxInt, totalOnes - onesCount)

    for l < len(nums) {
        if nums[l] == 1 {
            onesCount--
        }

        if nums[r % len(nums)] == 1 {
            onesCount++
        }

        ans = min(ans, totalOnes - onesCount)
        l++
        r++
    }

    return ans
}

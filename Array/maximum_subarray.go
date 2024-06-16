func max(a, b int) int {
    if a < b {
        return b
    }

    return a
}

func maxSubArray(nums []int) int {
    currSum, maxSum := 0, math.MinInt

    for _, num := range nums {
        currSum = max(currSum + num, num)
        maxSum = max(maxSum, currSum)
    }

    return maxSum
}

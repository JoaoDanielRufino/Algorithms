// https://leetcode.com/problems/increasing-triplet-subsequence/description

func min(a, b int) int {
    if a < b {
        return a
    }

    return b
}

func max(a, b int) int {
    if a > b {
        return a
    }

    return b
}

func increasingTriplet(nums []int) bool {
    smallest, greater := make([]int, len(nums)), make([]int, len(nums))

    smallest[0] = nums[0]
    for i := 1; i < len(nums); i++ {
        smallest[i] = min(smallest[i-1], nums[i])
    }

    greater[len(nums)-1] = nums[len(nums)-1]
    for i := len(nums)-2; i >= 0; i-- {
        greater[i] = max(greater[i+1], nums[i])
    }

    for i := range nums {
        if smallest[i] < nums[i] && nums[i] < greater[i] {
            return true
        }
    }

    return false
}

// simplest one
func increasingTriplet(nums []int) bool {
    firstSmallest, secondSmallest := math.MaxInt, math.MaxInt

    for _, num := range nums {
        if num <= firstSmallest {
            firstSmallest = num
        } else if num <= secondSmallest {
            secondSmallest = num
        } else {
            return true
        }
    }

    return false
}

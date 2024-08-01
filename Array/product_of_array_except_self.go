// https://leetcode.com/problems/product-of-array-except-self/description

func productExceptSelf(nums []int) []int {
    n := len(nums)
    prefix, suffix := []int{nums[0]}, []int{nums[n-1]}

    for i := 1; i < n; i++ {
        prefix = append(prefix, prefix[i-1] * nums[i])
        suffix = append(suffix, suffix[i-1] * nums[n-1-i])
    }

    ans, r := []int{}, n-2
    for i := 0; i < n; i++ {
        if i == 0 {
            ans = append(ans, suffix[r])
        } else if i == n-1 {
            ans = append(ans, prefix[i-1])
        } else {
            ans = append(ans, prefix[i-1] * suffix[r])
        }

        r--
    }

    return ans
}

// more readable
func productExceptSelf(nums []int) []int {
    prefix, suffix := make([]int, len(nums)), make([]int, len(nums)) 
    
    prefix[0] = 1
    for i := 1; i < len(nums); i++ {
        prefix[i] = prefix[i-1] * nums[i-1]
    }
    
    suffix[len(nums)-1] = 1
    for i := len(nums)-2; i >= 0; i-- {
        suffix[i] = suffix[i+1] * nums[i+1]
    }
    
    ans := []int{}
    for i := range nums {
        ans = append(ans, prefix[i] * suffix[i])
    }
    
    return ans
}

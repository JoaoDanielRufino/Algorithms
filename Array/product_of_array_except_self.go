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
    n := len(nums)
    prefix, suffix := make([]int, n), make([]int, n)

    prefix[0] = 1
    suffix[0] = 1

    for i := 1; i < n; i++ {
        prefix[i] = prefix[i-1] * nums[i-1]
        suffix[i] = suffix[i-1] * nums[n-i]
    }

    ans := []int{}
    for i := 0; i < n; i++ {
        ans = append(ans, prefix[i] * suffix[n-1-i])
    }

    fmt.Println(prefix, suffix)

    return ans
}

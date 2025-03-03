// https://leetcode.com/problems/partition-array-according-to-given-pivot/description

func pivotArray(nums []int, pivot int) []int {
    less, equal, greater := []int{}, []int{}, []int{}

    for _, num := range nums {
        if num < pivot {
            less = append(less, num)
        } else if num > pivot {
            greater = append(greater, num)
        } else {
            equal = append(equal, num)
        }
    }

    return append(less, append(equal, greater...)...)
}

// Better
func pivotArray(nums []int, pivot int) []int {
    less, equal := 0, 0

    for _, num := range nums {
        if num < pivot {
            less++
        } else if num == pivot {
            equal++
        }
    }

    ans := make([]int, len(nums))
    lessIndex := 0
    equalIndex := less
    greater := less + equal
    for _, num := range nums {
        if num < pivot {
            ans[lessIndex] = num
            lessIndex++
        } else if num > pivot {
            ans[greater] = num
            greater++
        } else {
            ans[equalIndex] = num
            equalIndex++
        }
    }

    return ans
}

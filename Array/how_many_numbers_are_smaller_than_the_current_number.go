// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/

func lowerBound(nums []int, target int) int {
    l, r, index := 0, len(nums)-1, -1
    
    for l <= r {
        mid := (l + r) / 2
        
        if nums[mid] == target {
            index = mid
            r = mid - 1
        } else if nums[mid] < target {
            l = mid + 1
        } else {
            r = mid - 1
        }
    } 
    
    return index
}

func smallerNumbersThanCurrent(nums []int) []int {
    sorted := make([]int, len(nums))
    copy(sorted, nums)
    
    sort.Ints(sorted)
    
    ans := []int{}
    for _, num := range nums {
        index := lowerBound(sorted, num)
        ans = append(ans, index) 
    }
    
    return ans
}

// or with map
func smallerNumbersThanCurrent(nums []int) []int {
    sorted := make([]int, len(nums))
    copy(sorted, nums)
    
    sort.Ints(sorted)

    posMap := map[int]int{}

    for i := range sorted {
        if _, ok := posMap[sorted[i]]; !ok {
            posMap[sorted[i]] = i
        }
    }
    
    ans := []int{}
    for _, num := range nums {
        ans = append(ans, posMap[num]) 
    }
    
    return ans
}

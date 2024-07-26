// https://leetcode.com/problems/valid-mountain-array/description/

func validMountainArray(arr []int) bool {
    if len(arr) < 3 {
        return false
    }
    
    increase := true
    for i := 1; i < len(arr); i++ {
        if arr[i-1] == arr[i] {
            return false
        }
        
        if increase {
            if arr[i-1] > arr[i] {
                increase = false
                
                if i == 1 {
                    return false
                }
            }
        } else {
            if arr[i-1] <= arr[i] {
                return false
            }
        }
    }
    
    return !increase
}

// better
func validMountainArray(arr []int) bool {
    i, j := 0, len(arr)-1

    for i + 1 < len(arr) && arr[i] < arr[i+1] {
        i++
    }

    for j > 0 && arr[j-1] > arr[j] {
        j--
    }

    return i > 0 && j < len(arr)-1 && i == j
}

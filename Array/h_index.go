// https://leetcode.com/problems/h-index/description

func hIndex(citations []int) int {
    sort.Ints(citations)

    n := len(citations)
    for i := 0; i < n; i++ {
        if citations[i] >= n-i {
            return n-i
        }
    }

    return 0
}

// binary search
func getCitations(citations []int, h int) int {
    count := 0

    for _, citation := range citations {
        if citation >= h {
            count++
        }
    }

    return count
}

func hIndex(citations []int) int {
    maxVal := 0

    for _, citation := range citations {
        if maxVal < citation {
            maxVal = citation
        }
    }

    h, l, r := 0, 0, maxVal
    for l <= r {
        mid := (l + r) / 2
        count := getCitations(citations, mid)

        if count >= mid {
            h = mid
            l = mid + 1
        } else {
            r = mid - 1
        }
    }

    return h
}

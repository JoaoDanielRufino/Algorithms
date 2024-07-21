// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description

func min(a, b int) int {
    if a < b {
        return a
    }

    return b
}

func restoreMatrix(rowSum []int, colSum []int) [][]int {
    ans := make([][]int, len(rowSum))

    for i := range ans {
        ans[i] = make([]int, len(colSum))
    }
    
    for i := range rowSum {
        for j := range colSum {
            num := min(rowSum[i], colSum[j])
            ans[i][j] = num
            rowSum[i] -= num
            colSum[j] -= num
        }
    }

    return ans
}

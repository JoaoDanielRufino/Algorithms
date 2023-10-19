// https://leetcode.com/problems/path-with-minimum-effort/description

var dx = [4]int{1, -1, 0, 0}
var dy = [4]int{0, 0, 1, -1}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func canMove(heights [][]int, i, j int, seen [][]bool) bool {
    if i < 0 || i >= len(heights) {
        return false
    }

    if j < 0 || j >= len(heights[i]) {
        return false
    }

    return !seen[i][j]
}

func solve(heights [][]int, i, j, maxEffort int, seen [][]bool) bool {
    if i == len(heights) - 1 && j == len(heights[i]) - 1 {
        return true
    }

    seen[i][j] = true

    for k := 0; k < 4; k++ {
        x := i + dx[k]
        y := j + dy[k]
        if canMove(heights, x, y, seen) && abs(heights[i][j] - heights[x][y]) <= maxEffort && solve(heights, x, y, maxEffort, seen) {
            return true
        }
    }

    return false
}

func minimumEffortPath(heights [][]int) int {
    n := len(heights)
    m := len(heights[0])

    l, r, ans := 0, int(math.Pow(10, 6)), 0
    for l <= r {
        mid := (l + r) / 2

        seen := make([][]bool, n)
        for i := 0; i < n; i++ {
            seen[i] = make([]bool, m)
        }

        if solve(heights, 0, 0, mid, seen) {
            r = mid - 1
            ans = mid
        } else {
            l = mid + 1
        }
    }

    return ans
}

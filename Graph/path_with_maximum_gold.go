// https://leetcode.com/problems/path-with-maximum-gold

var (
    dx = []int{1, -1, 0, 0}
    dy = []int{0, 0, 1, -1}
)

func canMove(grid [][]int, x, y int) bool {
    if x < 0 || x >= len(grid) {
        return false
    }

    if y < 0 || y >= len(grid[x]) {
        return false
    }

    return grid[x][y] > 0
}

func solve(grid [][]int, x, y int) int {
    gold := grid[x][y]
    grid[x][y] = 0

    ans := gold
    for k := 0; k < len(dx); k++ {
        i := x + dx[k]
        j := y + dy[k]
        if canMove(grid, i, j) {
            ans = max(ans, gold + solve(grid, i, j))
        }
    }

    grid[x][y] = gold

    return ans
}

func getMaximumGold(grid [][]int) int {
    ans := 0

    for i := 0; i < len(grid); i++ {
        for j := 0; j < len(grid[i]); j++ {
            if grid[i][j] > 0 {
                ans = max(ans, solve(grid, i, j))
            }
        }
    }

    return ans
}

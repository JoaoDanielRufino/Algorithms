// https://leetcode.com/problems/swim-in-rising-water/description/

var (
    dx = [4]int{1, -1, 0, 0}
    dy = [4]int{0, 0, 1, -1}
)

func newMatrix(n, m int) [][]bool {
    matrix := make([][]bool, n)
    
    for i := range matrix {
        matrix[i] = make([]bool, m)
    }
    
    return matrix
}

func canMove(grid [][]int, seen[][]bool, elevation, i, j int) bool {
    if i < 0 || i >= len(grid) {
        return false
    }
    
    if j < 0 || j >= len(grid[i]) {
        return false
    }
    
    if seen[i][j] {
        return false
    }
    
    return grid[i][j] <= elevation
}

func canReach(grid [][]int, seen[][]bool, elevation, i, j int) bool {
    if grid[i][j] == grid[len(grid)-1][len(grid[i])-1] {
        return true
    }
    
    seen[i][j] = true
    
    for k := 0; k < len(dx); k++ {
        x := i + dx[k]
        y := j + dy[k]
        
        if canMove(grid, seen, elevation, x, y) && canReach(grid, seen, elevation, x, y) {
            return true 
        }
    }
    
    return false
}

func swimInWater(grid [][]int) int {
    minVal, maxVal := math.MaxInt, math.MinInt
    
    for i := range grid {
        for j := range grid[i] {
            if grid[i][j] > maxVal {
                maxVal = grid[i][j]
            }
            
            if grid[i][j] < minVal {
                minVal = grid[i][j]
            }
        }
    }
    
    ans := 0
    for minVal <= maxVal {
        mid := (minVal + maxVal) / 2
        
        seen := newMatrix(len(grid), len(grid[0]))
        
        if grid[0][0] <= mid && canReach(grid, seen, mid, 0, 0) {
            ans = mid
            maxVal = mid - 1
        } else {
            minVal = mid + 1
        }
    }
    
    return ans
}

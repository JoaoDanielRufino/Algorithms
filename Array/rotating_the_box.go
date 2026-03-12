// https://leetcode.com/problems/rotating-the-box/description/

func transpose(grid [][]byte) [][]byte {
    m, n := len(grid), len(grid[0])
    transposed := make([][]byte, n)

    for i := range transposed {
        transposed[i] = make([]byte, m)
    }

    for i := range m {
        for j := range n {
            transposed[j][i] = grid[i][j]
        }
    }

    return transposed
}

func reverse(row []byte) {
    l, r := 0, len(row)-1

    for l < r {
        row[l], row[r] = row[r], row[l]
        l++
        r--
    }
}

func rotateGrid(grid [][]byte) [][]byte {
    transposed := transpose(grid)
    
    for i := range transposed {
        reverse(transposed[i])
    }

    return transposed
}

func applyGravity(grid [][]byte) {
    m, n := len(grid), len(grid[0])

    for j := range n {
        fall := m-1
        for i := m-1; i >= 0; i-- {
            if grid[i][j] == '*' {
                fall = i-1
            } else if grid[i][j] == '#'{
                grid[i][j] = '.'
                grid[fall][j] = '#'
                fall--
            }
        }
    }
}

func rotateTheBox(boxGrid [][]byte) [][]byte {
    rotated := rotateGrid(boxGrid)

    applyGravity(rotated)

    return rotated
}

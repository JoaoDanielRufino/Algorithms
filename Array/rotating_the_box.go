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

    for i := range m {
        fall := n-1
        for j := n-1; j >= 0; j-- {
            if grid[i][j] == '*' {
                fall = j-1
            } else if grid[i][j] == '#'{
                if fall != j {
                    grid[i][fall] = '#'
                    grid[i][j] = '.'
                }
                fall--
            }
        }
    }
}

func rotateTheBox(boxGrid [][]byte) [][]byte {
    applyGravity(boxGrid)

    rotated := rotateGrid(boxGrid)

    return rotated
}

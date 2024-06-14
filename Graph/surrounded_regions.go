// https://leetcode.com/problems/surrounded-regions/description

var (
    dx = [4]int{1, -1, 0, 0}
    dy = [4]int{0, 0, 1, -1}
)

func canVisit(board [][]byte, i, j int) bool {
    if i < 0 || i >= len(board) {
        return false
    }

    if j < 0 || j >= len(board[i]) {
        return false
    }

    return board[i][j] == 'O'
}

func dfs(board [][]byte, i, j int) {
    board[i][j] = '#'

    for k := range dx {
        x := i + dx[k]
        y := j + dy[k]

        if canVisit(board, x, y) {
            dfs(board, x, y)
        }
    }
}

func solve(board [][]byte) {
    m, n := len(board), len(board[0])

    for i := range board {
        if board[i][0] == 'O' {
            dfs(board, i, 0) 
        }

        if board[i][n-1] == 'O' {
            dfs(board, i, n-1)
        }
    }

    for j := range board[0] {
        if board[0][j] == 'O' {
            dfs(board, 0, j) 
        }

        if board[m-1][j] == 'O' {
            dfs(board, m-1, j)
        }
    }

    for i := range board {
        for j := range board[i] {
            if board[i][j] == '#' {
                board[i][j] = 'O'
            } else if board[i][j] == 'O' {
                board[i][j] = 'X'
            }
        }
    }
}

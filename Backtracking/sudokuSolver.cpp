bool solveSudoku(vector<vector<char>>& board) {
        int row, col;
        bool flag = false;
        
        for(row = 0; row < board.size(); row++) {
            for(col = 0; col < board.size(); col++) {
                if(board[row][col] == '.') {
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        
        if(!flag)
            return true;
        
        for(int i = 1; i <= 9; i++) {
            if(isSafe(board, row, col, i + '0')) {
                board[row][col] = i + '0';
                if(solveSudoku(board))
                    return true;
                board[row][col] = '.'; // Backtracking
            }
        }
        
        return false;
    }
    
    bool isSafe(vector<vector<char>> board, int row, int col, char num) {
        // Checking the row
        for(int i = 0; i < board.size(); i++) {
            if(board[row][i] == num)
                return false;
        }
        
        // Checking the col
        for(int i = 0; i < board.size(); i++) {
            if(board[i][col] == num)
                return false;
        }
        
        // Checking the grid 3x3
        row = row - row%3;
        col = col - col%3;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i+row][j+col] == num)
                    return false;
            }
        }
        
        return true;
    }

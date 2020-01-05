// https://leetcode.com/problems/word-search/

class Solution {
public:
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    
    bool solve(vector<vector<char>>& board, string word, int index, int x, int y) {
        if(x < 0 || x >= board.size() || y < 0 || y >= board[x].size())
            return false;
        
        if(index == word.size())
            return true;
        
        if(word[index] != board[x][y])
            return false;
        
        char tmp = board[x][y];
        board[x][y] = '#';
        for(int i = 0; i < 4; i++) {
            if(solve(board, word, index + 1, x + dx[i], y + dy[i]))
                return true;    
        }
        board[x][y] = tmp;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {        
        int x = -1, y = -1;
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(word.size() == 1)
                        return true;
                    
                    x = i;
                    y = j;
                    if(solve(board, word, 0, x, y))
                        return true;
                }
            }
        }
        
        return false;
    }
};
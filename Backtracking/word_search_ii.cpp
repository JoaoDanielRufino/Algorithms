struct Node {
    vector<Node*> child;
    bool isEnd;

    Node() {
        child = vector<Node*> (26, nullptr);
        isEnd = false;
    }
};

class Trie {
private:
    Node *root;

public:
    Trie() {
        this->root = new Node();
    }

    void addWord(string word) {
        Node *current = this->root;

        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(!current->child[index])
                current->child[index] = new Node();
            current = current->child[index];
        }

        current->isEnd = true;
    }

    bool isWord(string word) {
        Node *current = this->root;

        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(!current->child[index])
                return false;
            current = current->child[index];
        }

        return current->isEnd;
    }

    Node* getRoot() {
        return this->root;
    }
};

class Solution {
public:
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    bool OK(vector<vector<char>>& board, int i, int j, Node *trieRoot) {
        if(i < 0 || i >= board.size())
            return false;

        if(j < 0 || j >= board[i].size())
            return false;

        if(board[i][j] == '#')
            return false;

        return trieRoot->child[board[i][j] - 'a'];
    }

    vector<string> solve(vector<vector<char>>& board, string current, int i, int j, Node *trieRoot) {
        vector<string> ans;
        if(trieRoot->isEnd) {
            ans.push_back(current);
            trieRoot->isEnd = false;
        }

        char tmp = board[i][j];
        board[i][j] = '#';

        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(OK(board, x, y, trieRoot)) {
                char next = board[x][y];
                vector<string> subAns = solve(board, current + next, x, y, trieRoot->child[next - 'a']); 
                ans.insert(ans.end(), subAns.begin(), subAns.end());
            }
        } 

        board[i][j] = tmp;

        return ans;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        Trie trie;

        for(string word : words) {
            trie.addWord(word);
        }

        Node *trieRoot = trie.getRoot();
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                int index = board[i][j] - 'a';
                string c;
                if(trieRoot->child[index]) {
                    vector<string> subAns = solve(board, c + board[i][j], i, j, trieRoot->child[index]);
                    ans.insert(ans.end(), subAns.begin(), subAns.end());
                }
            }
        }

        return ans;
    }
};

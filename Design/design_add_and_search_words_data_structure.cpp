// https://leetcode.com/problems/design-add-and-search-words-data-structure/

struct Node {
    Node *next[26];
    bool isEndOfWord;
    Node() {
        for(int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class WordDictionary {
public:
    Node *root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *tmp = root;
        
        for(char c : word) {
            int index = c - 'a';
            if(!tmp->next[index])
                tmp->next[index] = new Node();
            tmp = tmp->next[index];
        }
        
        tmp->isEndOfWord = true;
    }
    
    bool solve(Node *root, string word, int i) {
        if(!root)
            return false;
        
        if(i == word.size())
            return root->isEndOfWord;
        
        if(word[i] != '.')
            return solve(root->next[word[i] - 'a'], word, i+1);
        
        for(int j = 0; j < 26; j++) {
            if(solve(root->next[j], word, i+1))
                return true;
        }
        
        return false;
    }
    
    bool search(string word) {
        return solve(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

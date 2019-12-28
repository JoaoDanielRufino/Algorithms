// https://leetcode.com/problems/word-break/

struct Node {
    Node *child[26];
    bool isEnd;
    
    Node() {
        for(int i = 0; i < 26; i++)
            child[i] = nullptr;
        isEnd = false;
    }
};

class Trie {
    public:
        Node *root;
        unordered_map<string, bool> dp;
    
        Trie() {
            root = new Node();
        }
    
        void insert(string key) {
            Node *tmp = root;
            
            for(int i = 0; i < key.size(); i++) {
                int index = key[i] - 'a';
                if(!tmp->child[index])
                    tmp->child[index] = new Node();
                tmp = tmp->child[index];
            }
            
            tmp->isEnd = true;
        }
    
        bool search(string key) {
            Node *tmp = root;
            
            for(int i = 0; i < key.size(); i++) {
                int index = key[i] - 'a';
                if(!tmp->child[index])
                    return false;
                tmp = tmp->child[index];
            }
            
            return tmp->isEnd;
        }
    
        bool wb(string s) {
            if(!s.size())
                return true;
            
            if(dp.count(s))
                return dp[s];
            
            for(int i = 1; i <= s.size(); i++) {
                if(search(s.substr(0, i)) && wb(s.substr(i, s.size())))
                    return dp[s.substr(i, s.size())] = true;
            }
            
            return dp[s] = false;
        }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        
        for(int i = 0; i < wordDict.size(); i++)
            trie.insert(wordDict[i]);
        
        return trie.wb(s);
    }
};
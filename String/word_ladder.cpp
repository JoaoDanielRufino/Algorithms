// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    vector<string> findAdj(string s, unordered_set<string>& hash) {
        vector<string> adj;
        
        for(char c = 'a'; c <= 'z'; c++) {
            for(int i = 0; i < s.size(); i++) {
                char tmp = s[i];
                s[i] = c;
                if(hash.count(s)) {
                    adj.push_back(s);
                    hash.erase(s);
                }
                s[i] = tmp;
            }
        }
        
        return adj;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hash(wordList.begin(), wordList.end());
        
        if(!hash.count(endWord))
            return 0;
        
        int count = 0;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()) {
            count++;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                string s = q.front();
                q.pop();
                if(s == endWord)
                    return count;
                vector<string> adj = findAdj(s, hash);
                for(string str : adj)
                    q.push(str);
            }
        }
        
        return 0;
    }
};
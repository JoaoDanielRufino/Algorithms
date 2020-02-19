// https://leetcode.com/problems/longest-string-chain/
// https://www.youtube.com/watch?v=zqe_zIkyVGQ

// Solution 1
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string a, const string b) {
           return a.size() < b.size(); 
        });
        
        unordered_map<string, int> dp;
        int res = 0;
        for(string word : words) {
            for(int i = 0; i < word.size(); i++) {
                string tmp = word.substr(0, i) + word.substr(i+1);
                dp[word] = max(dp[word], 1 + dp[tmp]);
            }
            res = max(res, dp[word]);
        }
        
        return res;
    }
};

// Solution 2
class Solution {
public:
    vector< vector<int> > edges;
    vector<int> dp;
    
    int solve(int v) {
        if(dp[v])
            return dp[v];
        
        dp[v] = 1;
        for(int u : edges[v])
            dp[v] = max(dp[v], 1 + solve(u));
        
        return dp[v];
    }
    
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> position;
        
        for(int i = 0; i < words.size(); i++)
            position[words[i]] = i;
        
        edges.assign(words.size(), vector<int>());
        dp.assign(words.size(), 0);
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++) {
                string tmp = words[i].substr(0, j) + words[i].substr(j+1);
                if(position.count(tmp))
                    edges[position[tmp]].push_back(i);
            }
        }
        
        int res = 0;
        for(int i = 0; i < words.size(); i++)
            res = max(res, solve(i));
        
        return res;
    }
};
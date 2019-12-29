// https://leetcode.com/problems/word-break-ii/
// https://www.youtube.com/watch?v=pu9z4qxp76c

class Solution {
public:
    unordered_map<string, vector<string> > dp;
    
    vector<string> solve(string s, set<string> st) {
        vector<string> res;
        if(!s.size())
            return res;
        
        if(dp.count(s))
            return dp[s];
        
        if(st.count(s))
            res.push_back(s);
        
        for(int i = 1; i < s.size(); i++) {
            string sufix = s.substr(i);
            if(st.count(sufix)) {           
                vector<string> aux = solve(s.substr(0, i), st);
                for(int i = 0; i < aux.size(); i++)
                    res.push_back(aux[i] + " " + sufix);
            }
        }
        
        return dp[s] = res;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        
        return solve(s, st);
    }
};
// https://leetcode.com/problems/palindrome-partitioning/

// Solution 1
class Solution {
public:
    vector< vector<string> > res;
    
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        
        while(l < r) {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        
        return true;
    }
    
    void solve(string s, int start, vector<string> curr) {
        if(start >= s.size()) {
            res.push_back(curr);
            return;
        }
        
        for(int i = start; i < s.size(); i++) {
            string sub = s.substr(start, i-start+1);
            if(isPalindrome(sub)) {
                curr.push_back(sub);
                solve(s, i+1, curr);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        solve(s, 0, vector<string>());
        
        return res;
    }
};

// Solution 2
class Solution {
public:
    unordered_map<int, vector<vector<string>>> dp;
    
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        
        while(l < r) {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        
        return true;
    }
    
    vector<vector<string>> solve(string s, int start) {
        vector<vector<string>> res;
        
        if(start >= s.size())
            return res;
        
        if(dp.count(start))
            return dp[start];
        
        for(int i = start; i < s.size(); i++) {
            string sub = s.substr(start, i-start+1);
            if(isPalindrome(sub)) {
                vector<vector<string>> aux = solve(s, i+1);
                vector<string> tmp;
                
                if(!aux.size()) {
                    tmp.push_back(sub);
                    res.push_back(tmp);
                    return dp[start] = res;
                }
                
                for(int i = 0; i < aux.size(); i++) {
                    tmp.clear();
                    tmp.push_back(sub);
                    for(string a : aux[i])
                        tmp.push_back(a); 
                    res.push_back(tmp);
                }
                
            }
        }
        
        return dp[start] = res;
    }
    
    vector<vector<string>> partition(string s) {
        return solve(s, 0);
    }
};

// Solution 3
class Solution {
public:
    vector< vector<string> > res;

    void solve(string s, int start, vector<string> curr, vector<vector<bool>> isPalindrome) {
        if(start >= s.size()) {
            res.push_back(curr);
            return;
        }
        
        for(int i = start; i < s.size(); i++) {
            if(isPalindrome[start][i]) {
                curr.push_back(s.substr(start, i-start+1));
                solve(s, i+1, curr, isPalindrome);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> isPalindrome(s.size()+1, vector<bool>(s.size()+1, false));

        for(int i = 0; i < s.size(); i++)
            isPalindrome[i][i] = true;
        
        for(int l = 2; l <= s.size(); l++) {
            for(int i = 0; i <= s.size()-l; i++) {
                int j = i + l - 1;
                if(l == 2)
                    isPalindrome[i][j] = s[i] == s[j];
                else
                    isPalindrome[i][j] = s[i] == s[j] && isPalindrome[i+1][j-1];
            }
        }
        
        solve(s, 0, vector<string>(), isPalindrome);
        
        return res;
    }
};
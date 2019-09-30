// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> res;
    unordered_map<int, string> mymap;
    
    void createMap() {
        mymap[2] = "abc";
        mymap[3] = "def";
        mymap[4] = "ghi";
        mymap[5] = "jkl";
        mymap[6] = "mno";
        mymap[7] = "pqrs";
        mymap[8] = "tuv";
        mymap[9] = "wxyz";
    }
    
    void solve(string digits, string current, int iStart, int n) {
        if(n > digits.size())
            return;
        
        if(n == digits.size()) {
            res.push_back(current);
            return;
        }
        
        for(int i = iStart; i < digits.size(); i++) {
            int k = digits[i] - '0';
            string aux = mymap[k];
            for(int j = 0; j < aux.size(); j++) {
                current += aux[j];
                solve(digits, current, i+1, n+1);
                current.pop_back();
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits == "") {
            return res;
        }
        
        createMap();
        
        solve(digits, "", 0, 0);
        
        return res;
    }
};
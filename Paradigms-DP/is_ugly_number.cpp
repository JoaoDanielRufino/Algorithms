// https://leetcode.com/problems/ugly-number/

class Solution {
public:
    map<long int, bool> dp;
    
    bool solve(int num, long int current) {
        if(current > num)
            return false;
        
        if(current == num)
            return true;
        
        if(dp.count(current))
            return dp[current];
        
        return dp[current] = solve(num, current * 2L) || solve(num, current * 3L) || solve(num, current * 5L);
    }
    
    bool isUgly(int num) {
        return solve(num, 1L);
    }
};
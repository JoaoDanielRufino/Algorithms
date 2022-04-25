// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1/?page=4&company[]=Amazon&sortBy=submissions#
// https://www.youtube.com/watch?v=xmguZ6GbatA

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int ans = 0;
        unordered_map<int, int> mp;
        
        int curr = 0;
        for(int i = 0; i < A.size(); i++) {
            curr += A[i];
            
            if(!curr)
                ans = i+1;
            
            if(mp.find(curr) != mp.end())
                ans = max(ans, i - mp[curr]);
            else
                mp[curr] = i;
        }
        
        return ans;
    }
};

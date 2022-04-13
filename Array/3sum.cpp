// https://leetcode.com/problems/3sum/

// Better solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        vector<vector<int>> res;
        
        if(A.size() < 3)
            return res;
        
        sort(A.begin(), A.end());
        
        for(int i = 0; i < A.size()-2; i++) {
            if(A[i] > 0)
                break;
            
            if(i > 0 && A[i] == A[i-1])
                continue;
            
            int l = i+1;
            int r = A.size()-1;
            while(l < r) {
                int sum = A[i] + A[l] + A[r];
                if(!sum) {
                    res.push_back({A[i], A[l], A[r]});
                    int lastLeft = A[l];
                    int lastRight = A[r];
                    
                    while(l < r && lastLeft == A[l])
                        l++;
                    while(l < r && lastRight == A[r])
                        r--;
                }
                else if(sum > 0)
                    r--;
                else
                    l++;
            }
        }
        
        return res;
    }
};

// Worst solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        set<vector<int>> st;
        
        if(A.size() < 3)
            return vector<vector<int>>();
        
        sort(A.begin(), A.end());
        
        for(int i = 0; i < A.size()-2; i++) {
            int l = i+1;
            int r = A.size()-1;
            while(l < r) {
                int sum = A[i] + A[l] + A[r];
                if(!sum) {
                    st.insert({A[i], A[l], A[r]});
                    l++;
                    r--;
                }
                else if(sum > 0)
                    r--;
                else
                    l++;
            }
        }
        
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};

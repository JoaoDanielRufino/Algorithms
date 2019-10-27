// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    bool isCommon(vector<string> vet, int len) {
        string aux = vet[0];
        
        for(int i = 1; i < vet.size(); i++) {
            int j = 0;
            while(j < len && j < vet[i].size()) {
                if(aux[j] != vet[i][j])
                    return false;
                j++;
            }
        }
        
        return true;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size())
            return "";
        
        int l, r, mid, minLen;
        string prefix;
        
        minLen = strs[0].size();
        for(int i = 1; i < strs.size(); i++)
            minLen = minLen > strs[i].size() ? strs[i].size() : minLen;
        
        l = 0;
        r = minLen;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(isCommon(strs, mid)) {
                prefix = strs[0].substr(0, mid);
                l = mid+1;
            }
            else
                r = mid-1;
        }
        
        return prefix;
    }
};
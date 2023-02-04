// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> hash;
        vector<int> res;
        
        int count = 0;
        for(int i = 0; i < p.size(); i++) {
            hash[p[i]]++;
            hash[s[i]]--;
        }
        
        int l = 0;
        int r = p.size()-1;
        while(r < s.size()) {
            bool anagram = true;
            for(auto it : hash) {
                if(it.second) {
                    anagram = false;
                    break;
                }
            }
            
            if(anagram)
                res.push_back(l);
            
            hash[s[l]]++;
            l++;
            r++;
            if(r >= s.size())
                break;
            hash[s[r]]--;
        }
        
// Easier solution
class Solution {
public:
    bool equal(vector<int>& a, vector<int>& b) {
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i])
                return false;
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if(p.size() > s.size())
            return ans;

        vector<int> mpS(26), mpP(26);

        for(int i = 0; i < p.size(); i++) {
            mpP[p[i] - 'a']++;
            mpS[s[i] - 'a']++;
        }

        int l = 0;
        int r = p.size() - 1;
        while(r < s.size()) {
            if(equal(mpS, mpP))
                ans.push_back(l);

            mpS[s[l] - 'a']--;

            l++;
            r++;

            if(r >= s.size())
                break;

            mpS[s[r] - 'a']++;
        }

        return ans;
    }
};
        
        return res;
    }
};

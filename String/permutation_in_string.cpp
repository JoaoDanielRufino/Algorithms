// https://leetcode.com/problems/permutation-in-string/description/

class Solution {
public:
    bool equal(vector<int>& a, vector<int>& b) {
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i])
                return false;
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;

        vector<int> mpA(26), mpB(26);

        for(int i = 0; i < s1.size(); i++) {
            mpA[s1[i] - 'a']++;
            mpB[s2[i] - 'a']++;
        }

        int l = 0;
        int r = s1.size() - 1;
        while(r < s2.size()) {
            if(equal(mpA, mpB))
                return true;

            mpB[s2[l] - 'a']--;

            l++;
            r++;

            if(r >= s2.size())
                break;

            mpB[s2[r] - 'a']++;
        }

        return false;
    }
};

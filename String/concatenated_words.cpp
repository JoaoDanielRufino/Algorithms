// https://leetcode.com/problems/concatenated-words/description/

class Solution {
public:
    bool solve(string word, unordered_set<string>& st) {
        for(int i = 0; i < word.size(); i++) {
            string prefix = word.substr(0, i + 1);
            string suffix = word.substr(i + 1); 
            if(st.count(prefix)) {
                if(st.count(suffix) || solve(suffix, st))
                    return true;
            }
        }

        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        vector<string> ans;

        for(string word : words) {
            if(solve(word, st))
                ans.push_back(word);
        }

        return ans;
    }
};

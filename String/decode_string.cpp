// https://leetcode.com/problems/decode-string/

class Solution {
public:
    pair<int, int> findNum(string& s, int index) {
        int num = 0, len = 0;
        
        while(s[index] >= '0' && s[index] <= '9') {
            num = num * 10 + (s[index] - '0');
            len++;
            index++;
        }
        
        return make_pair(num, len);
    }
    
    int findLenSubstring(string& s, int start) {
        int count = 1, len;
        
        for(int i = start; i < s.size(); i++) {
            if(s[i] == '[')
                count++;
            else if(s[i] == ']')
                count--;
            if(!count) {
                len = i - start;
                break;
            }
        }

        return len;
    }
    
    string decodeString(string s) {
        string res;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= 'a' && s[i] <= 'z')
                res += s[i];
            else if(s[i] >= '0' && s[i] <= '9') {
                pair<int, int> num = findNum(s, i);
                int len = findLenSubstring(s, i + num.second + 1);
                string decodedString = decodeString(s.substr(i + num.second + 1, len));
                while(num.first--)
                    res += decodedString;
                i += len + num.second;
            }
            
        }
        
        return res;
    }
};

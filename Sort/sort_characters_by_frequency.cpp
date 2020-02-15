// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:    
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        
        for(char c : s)
            mp[c]++;
        
        priority_queue< pair<int,char> > pq;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            pq.push(make_pair(it->second, it->first));
        }
        
        int i = 0;
        while(!pq.empty()) {
            int freq = pq.top().first;
            char c = pq.top().second;
            pq.pop();
            while(freq) {
                s[i++] = c;
                freq--;
            }
        }
        
        return s;
    }
};
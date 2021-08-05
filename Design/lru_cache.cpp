// https://leetcode.com/problems/lru-cache/

class LRUCache {
private:
    list<int> l;
    unordered_map<int, pair<list<int>::iterator, int>> mp;
    int size;
    
    void shiftFront(int key) {
        l.erase(mp[key].first);
        l.push_front(key);
        mp[key].first = l.begin();
    }
    
public:
    LRUCache(int capacity) {
        size = capacity;
    }
        
    int get(int key) {
        if(!mp.count(key))
            return -1;
        
        shiftFront(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            shiftFront(key);
            mp[key].second = value;
            return;
        }
        
        if(mp.size() == size) {
            mp.erase(l.back());
            l.pop_back();
        }
        
        l.push_front(key);
        mp[key] = make_pair(l.begin(), value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

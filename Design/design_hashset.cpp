// https://leetcode.com/problems/design-hashset/description/

class MyHashSet {
private: 
    int size;
    vector<vector<int>> vet;

    int hash(int key) {
        return key % size;
    }
public:
    MyHashSet() {
        size = 1009; // prime number
        vet.assign(size, vector<int>());
    }
    
    void add(int key) {
        int h = hash(key);
        if(!contains(key))
            vet[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);

        for(int i = 0; i < vet[h].size(); i++) {
            if(vet[h][i] == key)
                vet[h].erase(vet[h].begin() + i);
        }
    }
    
    bool contains(int key) {
        int h = hash(key);

        for(int elem : vet[h]) {
            if(elem == key)
                return true;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

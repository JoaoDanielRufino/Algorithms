// https://leetcode.com/problems/smallest-number-in-infinite-set/description/

class SmallestInfiniteSet {
public:
    set<int> st;
    int current;

    SmallestInfiniteSet() {
        current = 1;
    }
    
    int popSmallest() {
        int smallest;

        if(st.empty()) {
            smallest = current++;
        } else {
            smallest = *st.begin();
            st.erase(smallest);
        }

        return smallest;
    }
    
    void addBack(int num) {
        if(num < current)
            st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

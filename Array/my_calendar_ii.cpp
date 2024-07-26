// https://leetcode.com/problems/my-calendar-ii/description/

class MyCalendarTwo {
public:
    map<int, int> events; 
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        this->events[start]++;
        this->events[end]--;
        
        int count = 0;
        
        for(auto it = this->events.begin(); it != this->events.end(); it++) {
            count += it->second;
            
            if (count == 3) {
                this->events[start]--;
                this->events[end]++;
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

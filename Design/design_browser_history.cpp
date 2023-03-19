// https://leetcode.com/problems/design-browser-history/description/

class BrowserHistory {
public:
    stack<string> backS, forwardS;
    string current;

    BrowserHistory(string homepage) {
        current = homepage;
    }
    
    void visit(string url) {
        backS.push(current);
        current = url;
        while(!forwardS.empty()) {
            forwardS.pop();
        }
    }
    
    string back(int steps) {
        while(steps-- && backS.size()) {
            forwardS.push(current);
            current = backS.top();
            backS.pop();
        }

        return current;
    }
    
    string forward(int steps) {
        while(steps-- && forwardS.size()) { 
            backS.push(current);
            current = forwardS.top();
            forwardS.pop();
        }

        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

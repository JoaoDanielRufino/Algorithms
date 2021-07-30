// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> seen;
    
    bool hasCycle(int v, vector<bool> stack) {
        seen[v] = true;
        stack[v] = true;
        
        for(int adj : graph[v]) {
            if(stack[adj])
                return true;
            
            if(!seen[adj] && hasCycle(adj, stack))
                return true;
        }
        
        stack[v] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.assign(numCourses, vector<int>());
        seen.assign(numCourses, false);
        
        for(int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<bool> stack(numCourses, false);
        for(int i = 0; i < numCourses; i++) {
            if(!seen[i] && hasCycle(i, stack))
                return false;
        }
        
        return true;
    }
};

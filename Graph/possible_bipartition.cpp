// https://leetcode.com/problems/possible-bipartition/description/

// This is an algorithm to check if given graph can be bipartite

class Solution {
public:
    bool solve(vector<vector<int>>& graph, int current, bool color, vector<int>& colors) {
        colors[current] = color;

        for(int adj : graph[current]) {
            if(colors[adj] == color)
                return false;
                
            if(colors[adj] == -1 && !solve(graph, adj, !color, colors)) 
                return false;
        }

        return true;
    }

    bool canBipart(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), -1);

        for(int i = 0; i < graph.size(); i++) {
            if(colors[i] == -1 && !solve(graph, i, true, colors))
                return false;
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);

        for(vector<int> dislike : dislikes) {
            graph[dislike[0]-1].push_back(dislike[1]-1);
            graph[dislike[1]-1].push_back(dislike[0]-1);
        }

        return canBipart(graph);
    }
};

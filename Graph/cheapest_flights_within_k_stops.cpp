// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

class Solution {
public:
    int solve(vector<vector<pair<int, int>>>& graph, int src, int dst, int k) {
        vector<int> dist(graph.size(), INT_MAX);
        queue<pair<int, int>> q;
        
        q.push({ src, 0 });
        while(!q.empty() && k >= 0) {
            int size = q.size();
            while(size--) {
                pair<int, int> node = q.front();
                q.pop();

                for(pair<int, int> adj : graph[node.first]) {
                    if(node.second + adj.second < dist[adj.first]) {
                        dist[adj.first] = node.second + adj.second;
                        q.push({ adj.first, dist[adj.first] });
                    }
                }
            }
            k--;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        vector<bool> seen(n);

        for(vector<int> flight : flights) {
            graph[flight[0]].push_back({ flight[1], flight[2] });
        }

        return solve(graph, src, dst, k);  
    }
};

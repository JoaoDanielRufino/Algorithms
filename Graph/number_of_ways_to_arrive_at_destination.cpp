class Solution {
public:
    int dijkstra(vector<vector<pair<int, int>>>& graph, int start, int end) {
        priority_queue<pair<long long, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
        vector<long long int> dist(graph.size(), LONG_MAX);
        vector<int> ways(graph.size(), 0);

        dist[start] = 0;
        ways[start] = 1;
        pq.push({ 0, start });
        while(!pq.empty()) {
            pair<long long int, int> current = pq.top();
            pq.pop();

            for(pair<int, int> adj : graph[current.second]) {
                if(dist[adj.first] > dist[current.second] + adj.second) {
                    dist[adj.first] = dist[current.second] + adj.second;
                    ways[adj.first] = ways[current.second];
                    pq.push({ dist[adj.first], adj.first });
                } else if(dist[adj.first] == current.first + adj.second) {
                    ways[adj.first] = (ways[adj.first] + ways[current.second]) % 1000000007;
                }
            }
        }

        return ways[end];
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);

        for(vector<int> road : roads) {
            graph[road[0]].push_back({ road[1], road[2] });
            graph[road[1]].push_back({ road[0], road[2] });
        }

        return dijkstra(graph, 0, n-1);
    }
};

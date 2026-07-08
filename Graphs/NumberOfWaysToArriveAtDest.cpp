// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
class Solution {
    const int MOD = 1e9 + 7;

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : roads) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        vector<long long> ways(n, 0);
        ways[0] = 1;

        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            pq;
        pq.push({0, 0});

        // Dijkstra
        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            // Lazy Deletion
            if (cost > dist[node])
                continue;

            for (auto& [nei, weight] : graph[node]) {
                long long newDist = weight + cost;
                if (newDist < dist[nei]) {
                    dist[nei] = newDist;
                    ways[nei] = ways[node];
                    pq.push({newDist, nei});
                } else if (newDist == dist[nei]) {
                    ways[nei] = (ways[nei] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1] % MOD;
    }
};

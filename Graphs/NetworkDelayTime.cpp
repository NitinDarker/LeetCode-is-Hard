// https://leetcode.com/problems/network-delay-time/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for (auto &edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
        }

        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [cost, node] = pq.top(); pq.pop();

            // Lazy Deletion
            if (cost > dist[node]) continue;

            for (auto &[nei, wt] : graph[node]) {
                if (wt + cost < dist[nei]) {
                    dist[nei] = wt + cost;
                    pq.push({wt + cost, nei});
                }
            }
        }

        int time = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1;
            time = max(time, dist[i]);
        }
        return time;
    }
};

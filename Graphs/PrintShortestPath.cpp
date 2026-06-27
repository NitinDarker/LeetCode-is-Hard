// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
        int V = n + 1;
        vector<vector<pair<int, int>>> graph(V);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], c = edge[2];
            graph[u].push_back({v, c});
            graph[v].push_back({u, c});
        }

        int src = 1;
        int dest = n;
        
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        
        vector<int> parent(V, -1);
        parent[src] = src;

        // pq <- {cost, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            // Lazy pruning
            if (cost > dist[node]) continue;

            for (auto &[nei, weight] : graph[node]) {
                if (cost + weight < dist[nei]) {
                    dist[nei] = cost + weight;
                    parent[nei] = node;
                    pq.push({cost + weight, nei});
                }
            }
        }

        if (dist[dest] == 1e9) {
            return {-1};
        }

        vector<int> res;
        int node = dest;
        while (parent[node] != node) {
            res.push_back(node);
            node = parent[node];
        }
        res.push_back(src);
        res.push_back(dist[dest]);
        reverse(res.begin(), res.end());
        return res;
    }
};

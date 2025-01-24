// 802. Find Eventual Safe State => LeetCode Daily Problem (Medium)

// There is a directed graph of n nodes with each node labeled from 0 to n - 1. 
// The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i,
// meaning there is an edge from node i to each node in graph[i].
// A node is a terminal node if there are no outgoing edges.
// A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

class Solution {
    bool dfs(vector<vector<int>> &neighbors, unordered_map<int, bool> &mpp, int node) {
        if (neighbors[node].size() == 0) {
            mpp[node] = true;
            return true;
        }
        if (mpp.find(node) != mpp.end()) {
            return mpp[node];
        }
        mpp[node] = false;
        for (int nei: neighbors[node]) {
            if (dfs(neighbors, mpp, nei) == false) {
                return false;
            }
        }
        mpp[node] = true;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> safeNodes;
        unordered_map<int, bool> mpp;
        for (int i = 0; i < n; i++) {
            if (dfs(graph, mpp, i)) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};

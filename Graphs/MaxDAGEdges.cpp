// https://www.geeksforgeeks.org/problems/max-dag-edges/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>> &edges) {
        return (V * (V - 1)) / 2 - edges.size();
    }
};

/* In a DAG, all edges have one consistent direction. If we ever add an edge in the reverse direction, it creates a cycle.
So to keep it acyclic, we can only add edges in the same direction as the topological order (clockwise only).
Total possible forward edges = V*(V - 1)/2
Already present = E
Max additional = V(V - 1)/2 - E
*/

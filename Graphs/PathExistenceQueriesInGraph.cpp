// https://leetcode.com/problems/path-existence-queries-in-a-graph-i/description/
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n, 0);
        int id = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i-1] > maxDiff) id++;
            comp[i] = id;
        }
        
        vector<bool> pathExist;
        for (auto &it : queries) {
            int u = it[0], v = it[1];
            if (comp[u] == comp[v]) pathExist.push_back(true);
            else pathExist.push_back(false);
        }
        return pathExist;
    }
};

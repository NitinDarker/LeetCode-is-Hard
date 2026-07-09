// https://leetcode.com/problems/minimum-deletion-cost-to-make-all-characters-equal/description/
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n = s.size();
        long long maxCost = -1, totalCost = 0;
        vector<long long> del(26, 0);
        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';
            del[ch] += cost[i];
            totalCost += cost[i];
            maxCost = max(maxCost, del[ch]);
        }
        return totalCost - maxCost;
    }
};

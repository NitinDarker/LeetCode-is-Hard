// https://leetcode.com/problems/xor-queries-of-a-subarray/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        vector<int> prefixSum;
        int xorSum = 0;
        for (int ele : arr) {
            xorSum ^= ele;
            prefixSum.push_back(xorSum);
        }
        vector<int> res;
        for (vector<int> &q : queries) {
            if (q[0] == 0) {
                res.push_back(prefixSum[q[1]]);
                continue;
            }
            int val = prefixSum[q[1]] ^ prefixSum[q[0] - 1];
            res.push_back(val);
        }
        return res;
    }
};

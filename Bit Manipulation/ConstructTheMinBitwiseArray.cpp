// https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int &num : nums) {
            if (!(num & 1)) {
                ans.push_back(-1);
                continue;
            }
            int j = 0;
            while (true) {
                int bit = ((num >> j) & 1);
                if (bit == 0) break;
                j++;
            }
            int x = (num & (~(1 << (j-1))));
            ans.push_back(x);
        }
        return ans;
    }
};

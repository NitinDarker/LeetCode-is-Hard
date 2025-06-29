/// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int numSubseq(vector<int> &nums, int target) {
        int mod = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> power(n+1, 1);
        for (int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] << 1) % mod; // same as x2
        }

        int i = 0, j = n-1;
        int count = 0;
        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                count += (power[j-i] % mod);
                i++;
            } else {
                j--;
            }
        }
        return count % mod;
    }
};

/// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
#include <bits/stdc++.h>
using namespace std;

// Space-Optmized Tabulation
class Solution {
  public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> prev(m + 1, 0);
        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            vector<int> curr(m + 1);
            for (int j = 1; j <= m; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                    maxi = max(maxi, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        return maxi;
    }
};

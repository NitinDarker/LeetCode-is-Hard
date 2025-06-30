/// https://leetcode.com/problems/longest-harmonious-subsequence/description/?envType=daily-question&envId=2025-06-30
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findLHS(vector<int> &nums) {
        unordered_map<int, int> freq;
        for (int ele : nums) freq[ele]++;
        int n = nums.size();
        int maxi = 0;
        for (int ele : nums) {
            if (freq.find(ele+1) != freq.end()) {
                maxi = max(maxi, freq[ele] + freq[ele+1]);
            }
        }
        return maxi;
    }
};

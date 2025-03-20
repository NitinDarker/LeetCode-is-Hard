// https://leetcode.com/problems/subsets/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        int comb = 0; // Bitwise combination 
        int n = nums.size();
        vector<vector<int>> res;
        int end = (1 << n); // Total subsets
        while (comb < end) {
            int currComb = comb;
            vector<int> arr;
            for (int i = 0; i < n; i++) {
                int bit = currComb & 1;
                if (bit == 1)
                    arr.push_back(nums[i]);
                currComb = currComb >> 1;
            }
            res.push_back(arr);
            comb++;
        }
        return res;
    }
};

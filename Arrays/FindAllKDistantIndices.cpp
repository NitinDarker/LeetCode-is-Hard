// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/?envType=daily-question&envId=2025-06-24
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
        vector<int> arr; // j where nums[j] == key
        int n = nums.size();

        for (int j = 0; j < n; j++) {
            if (key == nums[j]) arr.push_back(j);
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            for (int j : arr) {
                if (abs(i-j) <= k) {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};

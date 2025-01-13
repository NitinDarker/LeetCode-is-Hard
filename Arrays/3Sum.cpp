/* 15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that
i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    // Time Complexity: O(n^2 log n) -> Time Limit Exceeded
    // Space Complexity: O(3n) approx.
    vector<vector<int>> SumThree(vector<int> &nums) {
        int n = nums.size();
        set<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            unordered_set<int> mpp;
            // set<int> mpp  // May decrease or increase time complexity
            for (int j = i + 1; j < n; j++) {
                int k = -1 * (nums[i] + nums[j]);
                if (mpp.find(k) != mpp.end()) {
                    vector<int> triplet = {nums[i], nums[j], k};
                    sort(triplet.begin(), triplet.end());
                    ans.insert(triplet);
                }
                mpp.insert(nums[j]);
            }
        }
        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }

    // Two pointer approach -> Technically Three pointers
    // Time Complexity: O(n * log n) + O(n^2)
    // Space Complexity: O(1)
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0;
        while (i < n) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    k--;
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                } else {
                    k--;
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
            i++;
            while (i < n && nums[i] == nums[i - 1]) {
                i++;
            }
        }
        return ans;
    }
};
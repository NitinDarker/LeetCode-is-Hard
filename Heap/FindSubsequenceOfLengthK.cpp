// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/?envType=daily-question&envId=2025-06-28
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxSubsequence(vector<int> &nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> heap; // Min Heap
        
        int i = 0;
        while (heap.size() != k) heap.push(nums[i++]);
        while (i < n) {
            if (nums[i] > heap.top()) {
                heap.pop();
                heap.push(nums[i]);
            }
            i++;
        }

        unordered_map<int, int> mpp;
        while (!heap.empty()) {
            mpp[heap.top()]++;
            heap.pop();
        }
        vector<int> res;
        for (int ele : nums) {
            if (res.size() == k) break;
            if (mpp.find(ele) != mpp.end() && mpp[ele] > 0) {
                res.push_back(ele);
                mpp[ele]--;
            }
        }
        return res;
    }
};

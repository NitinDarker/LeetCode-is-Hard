// https://leetcode.com/problems/minimum-index-of-a-valid-split/description/?envType=daily-question&envId=2025-03-27
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumIndex(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for (int ele : nums) {
            mpp[ele]++;
        }

        int freq = 0;
        int dom = 0;

        for (auto it : mpp) {
            if (it.second > freq) {
                freq = it.second;
                dom = it.first;
            }
        }

        int leftFreq = 0;
        int rightFreq = freq;

        for (int i = 0; i < n; i++) {
            if (nums[i] == dom) {
                leftFreq += 1;
                rightFreq -= 1;
            }

            if ((double)leftFreq > ((double)(i+1))/2.0 && (double)rightFreq > ((double)n-i-1)/2.0) {
                return i;
            }
        }
        return -1;
    }
};

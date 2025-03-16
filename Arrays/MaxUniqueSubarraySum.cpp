// https://leetcode.com/contest/weekly-contest-441/problems/maximum-unique-subarray-sum-after-deletion/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    int maxSum(vector<int> &nums) {
        unordered_set<int> mpp;
        for (int ele: nums) {
            mpp.insert(ele);
        }
        int res = 0;
        int largest = INT_MIN;
        bool allNeg = true;
        for (auto ele: mpp) {
            if (ele > 0) {
                res += ele;
                allNeg = false;
            }
            if (ele > largest) largest = ele;
        }
        if (allNeg) return largest;
        return res;
    }
};

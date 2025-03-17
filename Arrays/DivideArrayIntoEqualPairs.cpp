#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    bool divideArray(vector<int> &nums) {
        int size = nums.size();
        unordered_map<int, int> mpp;
        for (int ele: nums) {
            mpp[ele]++;
        }
        for (auto ele: mpp) {
            if (ele.second % 2 != 0) return false;
        }
        return true;
    }
};

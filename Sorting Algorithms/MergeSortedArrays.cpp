// https://leetcode.com/problems/merge-sorted-array/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        int l = 0, r = 0;
        while (l < m && r < n) {
            if (nums1[l] <= nums2[r]) res.push_back(nums1[l++]);
            else res.push_back(nums2[r++]);
        }
        while (l < m) res.push_back(nums1[l++]);
        while (r < n) res.push_back(nums2[r++]);
        for (int i = 0; i < (m+n); i++) {
            nums1[i] = res[i];
        }
    }
};

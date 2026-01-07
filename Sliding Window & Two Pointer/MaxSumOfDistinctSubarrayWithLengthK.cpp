// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long maximumSubarraySum(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq;
        vector<int> res;
        long long windowSum = 0;
        long long maxi = 0;
        int l = 0, r = 0;
        while (r < k) {
            freq[arr[r]]++;
            windowSum += arr[r];
            r++;
        }
        if (freq.size() == k) maxi = max(windowSum, maxi);
        while (r < n) {
            freq[arr[r]]++;
            windowSum += arr[r];
            windowSum -= arr[l];
            freq[arr[l]]--;
            if (freq[arr[l]] == 0) freq.erase(arr[l]);
            if (freq.size() == k) maxi = max(windowSum, maxi);
            l++;
            r++;
        }
        return maxi;
    }
};

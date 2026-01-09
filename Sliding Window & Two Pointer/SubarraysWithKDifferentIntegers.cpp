// https://leetcode.com/problems/subarrays-with-k-different-integers/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        if (k < 0) return 0;
        int n = arr.size();
        unordered_map<int, int> freq;
        int l = 0, r = 0, cnt = 0;
        while (r < n) {
            freq[arr[r]]++;
            while (freq.size() > k) {
                freq[arr[l]]--;
                if (freq[arr[l]] == 0) freq.erase(arr[l]);
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k) {
        return countAtMostK(nums, k) - countAtMostK(nums, k-1);
    }
};

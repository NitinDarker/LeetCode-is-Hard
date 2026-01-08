// https://leetcode.com/problems/count-number-of-nice-subarrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Subarrays with oddCnt <= k
    int countAtMostKOdds(vector<int> &arr, int k) {
        if (k < 0) return 0;
        int n = arr.size();
        int l = 0, r = 0;
        int oddCnt = 0, res = 0;
        while (r < n) {
            if (arr[r] & 1) oddCnt++;
            while (oddCnt > k) {
                if (arr[l] & 1) oddCnt--;
                l++;
            }
            res += (r-l+1);
            r++;
        }
        return res;
    }

  public:
    int countSubarrays(vector<int> &arr, int k) {
        return countAtMostKOdds(arr, k) - countAtMostKOdds(arr, k-1);
    }
};

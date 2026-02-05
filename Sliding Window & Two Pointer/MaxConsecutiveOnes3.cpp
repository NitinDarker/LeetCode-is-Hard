// https://leetcode.com/problems/max-consecutive-ones-iii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestOnes(vector<int> &arr, int k) {
        int n = arr.size();
        int l = 0, r = 0;
        int maxSize = 0;
        while (r < n) {
            maxSize = max(maxSize, r-l);
            if (arr[r] == 1) {
                r++;
                continue;
            }
            if (arr[r] == 0 && k > 0) {
                r++;
                k--;
                continue;
            }
            while (k == 0) {
                if (arr[l] == 1) l++;
                else l++, k++;
            }
        }
        maxSize = max(maxSize, r - l);
        return maxSize;
    }
};

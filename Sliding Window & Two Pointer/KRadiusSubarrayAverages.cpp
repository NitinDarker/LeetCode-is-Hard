// leetcode.com/problems/k-radius-subarray-averages/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> getAverages(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> res(n, -1);
        int i = k;
        int windowSize = 2*k + 1;
        if (windowSize > n) {
            return res;
        }
        int l = 0, r = 0;
        long long curSum = 0;
        while (r < n && r - l != windowSize) {
            curSum += arr[r];
            r++;
        }
        res[i++] = curSum/windowSize;
        while (r < n) {
            curSum -= arr[l];
            curSum += arr[r];
            res[i] = curSum/windowSize;
            i++;
            l++;
            r++;
        }
        return res;
    }
};

// https://leetcode.com/problems/ways-to-make-a-fair-array/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int cntWays(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return 1;
        vector<int> evenPrefix(n, 0), oddPrefix(n, 0);
        evenPrefix[0] = arr[0];
        evenPrefix[1] = arr[0];
        oddPrefix[1] = arr[1];
        for (int i = 2; i < n; i++) {
            if (i % 2 == 0) {
                evenPrefix[i] = arr[i] + evenPrefix[i-2];
                oddPrefix[i] = oddPrefix[i-1];
            } else {
                oddPrefix[i] = arr[i] + oddPrefix[i-2];
                evenPrefix[i] = evenPrefix[i-1];
            }
        }
        int totalEven = evenPrefix[n-1];
        int totalOdd = oddPrefix[n-1];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int oddSum, evenSum;
            if (i % 2 == 0) {
                oddSum = oddPrefix[i] + totalEven - evenPrefix[i];
                evenSum = evenPrefix[i] - arr[i] + totalOdd - oddPrefix[i];
            } else {
                oddSum = oddPrefix[i] - arr[i] + totalEven - evenPrefix[i];
                evenSum = evenPrefix[i] + totalOdd - oddPrefix[i];
            }
            if (oddSum == evenSum) {
                cnt++;
            }
        }
        return cnt;
    }
};

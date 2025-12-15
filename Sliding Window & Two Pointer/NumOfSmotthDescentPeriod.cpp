// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        int i = 0;
        long long cnt = 0;
        while (i < n) {
            int j = i+1;
            while (j < n && prices[j] == prices[j-1] - 1) {
                j++;
            }
            long long k = j-i+1;
            cnt += (k) * (k-1) / 2;
            i = j;
        }
        return cnt;
    }
};

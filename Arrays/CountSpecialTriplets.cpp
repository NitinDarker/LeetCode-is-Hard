// https://leetcode.com/contest/weekly-contest-454/problems/count-special-triplets/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int specialTriplets(vector<int> &nums) {
        int mod = 1e9 + 7;
        unordered_map<int, long long> right, left;
        for (int ele : nums) {
            right[ele] += 1;
        }
        long long res = 0;
        // x...y...z
        for (long long y : nums) {
            long long num = y * 2;
            right[y]--;
            if (left[num] > 0 && right[num] > 0) {
                res +=  (left[num] * right[num]);
            }
            left[y] += 1;
        }
        res = res % mod;
        return res;
    }
};

// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/?envType=daily-question&envId=2025-06-10
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxDifference(string s) {
        vector<int> mpp(26, 0);
        for (char ch : s) {
            mpp[ch - 'a']++;
        }
        int maxOdd = 0;
        int minEven = INT_MAX;
        for (int it : mpp) {
            if (it == 0) continue;
            if (!(it & 1)) {
                minEven = min(minEven, it);
            } else {
                maxOdd = max(maxOdd, it);
            }
        }
        return maxOdd - minEven;
    }
};

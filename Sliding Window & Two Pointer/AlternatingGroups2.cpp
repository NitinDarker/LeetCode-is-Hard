// https://leetcode.com/problems/alternating-groups-ii/description/?envType=daily-question&envId=2025-03-09
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    int numberOfAlternatingGroups(vector<int> &colors, int k) {
        int n = colors.size();
        // Using Sliding Window
        int count = 0;
        int l = 0;
        for (int r = 1; r < (n+k-1); r++) {
            if (colors[r % n] == colors[(r-1) % n]) l = r;
            if (r-l+1 > k) l++;
            if (r-l+1 == k) count++;
        }
        return count;
    }
};

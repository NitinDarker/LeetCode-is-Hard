// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 1) return 1;
        unordered_set<char> uniq;
        uniq.insert(s[0]);
        int l = 0, r = 1;
        int maxi = 0;
        while (r < n) {
            if (uniq.count(s[r]) > 0) {
                uniq.erase(s[l]);
                l++;
            } else {
                uniq.insert(s[r]);
                r++;
            }
            maxi = max(maxi, r-l);
        }
        return maxi;
    }
};

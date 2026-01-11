// https://www.geeksforgeeks.org/problems/minimum-window-subsequence/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string minWindow(string &s1, string &s2) {
        int m = s1.length(), n = s2.length();
        int minLen = INT_MAX, start = 0, j = 0;
        while (j < m) {
            int k = 0;   // pointer for s2
            int end = j; // forward scan pointer for s1

            // -------- FORWARD SCAN --------
            while (end < m && k < n) {
                if (s1[end] == s2[k]) {
                    k++;
                }
                end++;
            }
            if (k < n) break;

            // -------- BACKWARD SHRINK --------
            k--;             
            int i = end - 1; // start shrinking from window end
            while (i >= j && k >= 0) {
                if (s1[i] == s2[k]) {
                    k--;
                }
                i--;
            }
            int len = end - i - 1; // Window is from (i+1) to (end-1)
            if (len < minLen) {
                minLen = len;
                start = i + 1;
            }
            j = i + 2; // Move j to next possible start
        }
        if (minLen == INT_MAX) return "";
        return s1.substr(start, minLen);
    }
};

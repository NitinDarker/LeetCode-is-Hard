/// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
#include <bits/stdc++.h>
using namespace std;

// Space-Optmized Tabulation
class Solution {
  public:
    int longestCommonSubstr(string &s1, string &s2) {
        int n = s1.length(), m = s2.length();
        vector<int> prev(m+1, 0);
        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            vector<int> curr(m+1);
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) {
                    curr[j] = 1 + prev[j-1];
                    maxi = max(maxi, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        return maxi;
    }
};

// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int codes = (1 << k);
        if (n-k+1 < codes) return false;
        vector<bool> vis(codes, false);
        int sub = 0;
        for (int i = 0; i < k; i++) {
            sub = ((sub << 1) | (s[i] - '0'));
        }
        for (int i = k; i < n; i++) {
            sub <<= 1;
            sub &= ((1 << k)-1);
            sub |= (s[i] - '0');
            vis[sub] = true;
        }
        for (int v : vis) if (!v) return false;
        return true;
    }
};

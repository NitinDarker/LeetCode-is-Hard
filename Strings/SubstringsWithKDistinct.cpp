// https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Count subtrings with <= k distinct 
    int helper(string &s, int k) {
        if (k < 0) return 0;
        int len = s.length();
        vector<int> freq(26, 0);
        int l = 0, r = 0, cnt = 0, dist = 0;
        while (r < len) {
            if (freq[s[r]-'a']++ == 0) dist++;
            while (dist > k) {
                if (--freq[s[l]-'a'] == 0) dist--;
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }

  public:
    int countSubstr(string& s, int k) {
        return helper(s, k) - helper(s, k-1);
    }
};

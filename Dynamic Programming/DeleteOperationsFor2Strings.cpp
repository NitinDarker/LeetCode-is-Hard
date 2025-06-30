/// https://leetcode.com/problems/delete-operation-for-two-strings/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int lcs(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<int> prev(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            vector<int> curr(m + 1, 0);
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[m];
    }

  public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        return n + m- (2 * lcs(word1, word2));
    }
};

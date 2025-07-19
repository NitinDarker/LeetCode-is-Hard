
/// https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(string s) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
        
        for (int i = 0; i < n; i += 2) {
            if (s[i] == 'T') {
                dp[i][i][1] = 1;
                dp[i][i][0] = 0;
            } else {
                dp[i][i][0] = 1;
                dp[i][i][1] = 0;
            }
        }
        
        for (int len = 3; len <= n; len += 2) {
            for (int i = 0; i + len <= n; i += 2) {
                int j = i + len - 1;
                for (int k = i + 1; k < j; k += 2) {
                    char op = s[k];
                    int leftTrue = dp[i][k-1][1];
                    int leftFalse = dp[i][k-1][0];
                    int rightTrue = dp[k+1][j][1];
                    int rightFalse = dp[k+1][j][0];
                    
                    if (op == '&') {
                        dp[i][j][1] += leftTrue * rightTrue;
                        dp[i][j][0] += leftTrue * rightFalse + leftFalse * rightTrue + leftFalse * rightFalse;
                    } else if (op == '|') {
                        dp[i][j][1] += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
                        dp[i][j][0] += leftFalse * rightFalse;
                    } else if (op == '^') {
                        dp[i][j][1] += leftTrue * rightFalse + leftFalse * rightTrue;
                        dp[i][j][0] += leftTrue * rightTrue + leftFalse * rightFalse;
                    }
                }
            }
        }
        return dp[0][n-1][1];
    }
};

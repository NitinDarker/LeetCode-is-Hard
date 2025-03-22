// https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int countSteps(string s, int first, vector<int> pos, int n) {
        int m = s.length();
        int count = 0;
        for (int i = first; i < m; i++) {
            if (s[i] == 'L') pos[1]--;
            else if (s[i] == 'R') pos[1]++;
            else if (s[i] == 'U') pos[0]--;
            else pos[0]++;
            
            if (pos[0] < 0 || pos[0] >= n) break;
            if (pos[1] < 0 || pos[1] >= n) break;

            count++;
        }
        return count;
    }

  public:
    vector<int> executeInstructions(int n, vector<int> &startPos, string s) {
        int m = s.length();
        vector<int> res(m, 0);
        for (int i = 0; i < m; i++) {
            res[i] = countSteps(s, i, startPos, n);
        }
        return res;
    }
};

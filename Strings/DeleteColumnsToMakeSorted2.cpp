// https://leetcode.com/problems/delete-columns-to-make-sorted-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), len = strs[0].length();
        int deletions = 0;
        vector<bool> alreadySorted(n-1, false);
        for (int col = 0; col < len; col++) {
            bool deleted = false;
            for (int row = 0; row < n-1; row++) {
                if (!alreadySorted[row] && strs[row][col] > strs[row+1][col]) {
                    deletions++;
                    deleted = true;
                    break;
                }
            }
            if (!deleted) {
                for (int row = 0; row < n-1; row++) {
                    alreadySorted[row] = alreadySorted[row] | strs[row][col] < strs[row+1][col];
                }
            }
        }
        return deletions;
    }
};

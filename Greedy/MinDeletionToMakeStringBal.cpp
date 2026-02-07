// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/
class Solution {
  public:
    int minimumDeletions(string s) {
        int bCount = 0;
        int del = 0;
        for (char c : s) {
            if (c == 'b') bCount++;
            else del = min(del + 1, bCount);
        }
        return del;
    }
};

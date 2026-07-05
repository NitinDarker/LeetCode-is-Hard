// https://leetcode.com/problems/largest-substring-between-two-equal-characters/
class Solution {
  public:
    int maxLengthBetweenEqualCharacters(string &s) {
        int n = s.length();
        int maxGap = -1;
        vector<int> first(26, -1);

        for (int i = 0; i < n; i++) {
            char ch = s[i] - 'a';
            if (first[ch] == -1) {
                first[ch] = i;
            } else {
                maxGap = max(maxGap, i-first[ch]-1);
            }
        }
        return maxGap;
    }
};

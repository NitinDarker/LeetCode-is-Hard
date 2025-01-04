class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_map<char, int> right;
        unordered_set<char> left;
        set<pair<char,char>> ans;
        for (char ch: s) {
            right[ch]++;
        }
        for (int i = 0; i < n; i++) {
            right[s[i]]--;
            for (char it: left) {
                if (right.find(it) != right.end() && right[it] > 0) {
                    ans.insert({it, s[i]});
                }
            }
            left.insert(s[i]);
        }
        return ans.size();
    }
};

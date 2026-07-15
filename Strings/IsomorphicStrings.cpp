// https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, char> mpp;
        unordered_set<char> vis;
        for (int i = 0; i < n; i++) {
            if (mpp.count(s[i]) && mpp[s[i]] != t[i]) return false;
            if (mpp.count(s[i]) && mpp[s[i]] == t[i]) continue;
            if (vis.count(t[i])) return false;
            mpp[s[i]] = t[i];
            vis.insert(t[i]);
        }
        return true;
    }
};

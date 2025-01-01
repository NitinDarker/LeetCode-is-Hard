class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        int l = 0, r = 0;
        while (l < slen && r < tlen) {
            if (s[l] == t[r]) {
                l++;
                r++;
            } else {
                r++;
            }
        }
        if (r == tlen && l != slen) {
            return false;
        } 
        return true;
    }
};

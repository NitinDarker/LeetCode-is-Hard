// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/?envType=daily-question&envId=2025-02-05

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m != n) return false;
        int diff = 0;
        int ind1 = -1, ind2 = -1;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                diff++;
                if (ind1 == -1) ind1 = i;
                else ind2 = i;
                if (diff > 2) return false;
            }
        }
        if (diff == 0) return true;
        if (diff == 1 || diff > 2) return false;
        swap(s1[ind1], s1[ind2]);
        if (s1 != s2) return false;
        return true;
    }
};

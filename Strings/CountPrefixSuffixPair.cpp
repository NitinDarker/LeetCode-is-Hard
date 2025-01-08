/* 3042. Count Prefix and Suffix Pairs I -> LeetCode Daily Problem

You are given a 0-indexed string array words.
Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:
isPrefixAndSuffix(str1, str2) returns true if str1 is both a prefix and a suffix of str2, and false otherwise.
For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.
Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.
*/

class Solution {
    bool isPrefixAndSuffix(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        int l = 0, r = 0;
        while (l < m && r < n) {
            if (str1[l] == str2[r]) {
                l++;
                r++;
            } else {
                return false;
            }
        }
        if (l != m) return false;
        l = m - 1;
        r = n - 1;
        while (l >= 0 && r >= 0) {
            if (str1[l] == str2[r]) {
                l--;
                r--;
            } else {
                return false;
            }
        }
        if (l != -1) return false;
        return true;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) count++;
            }
        }
        return count;
    }
};

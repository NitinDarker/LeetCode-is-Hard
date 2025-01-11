// 1400. Construct K Palindrome Strings -> LeetCode Daily Problem
// Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) {
            return false;
        } 
        // Counting frequency of every character
        unordered_map<char, int> mpp;
        for (char ch: s) {
            mpp[ch]++;
        }
        int oddCount = 0;
        for (auto i: mpp) {
            if (i.second % 2 != 0) {
                oddCount++;   
            }
        }
        if (oddCount > k) return false;
        return true;
    }
};

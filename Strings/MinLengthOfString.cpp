// 3223. Minimum Length of String After Operations -> LeetCode Daily Problem

// You are given a string s.
// You can perform the following process on s any number of times:
//     Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
//     Delete the closest character to the left of index i that is equal to s[i].
//     Delete the closest character to the right of index i that is equal to s[i].

// Return the minimum length of the final string s that you can achieve.

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        unordered_map<char, int> mpp;
        for (char ch : s) {
            mpp[ch]++;
        }
        int finalLength = 0;
        for (auto& i : mpp) {
            while (i.second >= 3) {
                i.second -= 2;
            }
            finalLength += i.second;
        }
        return finalLength;
    }
};

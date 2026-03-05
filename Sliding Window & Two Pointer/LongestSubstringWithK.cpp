// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        int dist = 0, size = -1;
        int i = 0, j = 0;
        while (j < n) {
            int ch = s[j] - 'a';
            if (freq[ch]++ == 0) dist++;
            while (dist > k) {
                int prev = s[i] - 'a';
                if (--freq[prev] == 0) dist--;
                i++;
            }
            j++;
            if (dist == k) size = max(size, j-i);
        }
        return size;
    }
};

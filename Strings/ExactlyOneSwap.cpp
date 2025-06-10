// https://www.geeksforgeeks.org/problems/exactly-one-swap--170637/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countStrings(string &s) {
        int n = s.length();

        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        if (freq.size() == 1) {
            return 1; 
        }

        long long total_swaps = (long long)n * (n - 1) / 2;

        long long identical_char_swaps = 0;
        for (auto const &pair : freq) {
            int count = pair.second;
            if (count >= 2) {
                identical_char_swaps += (long long)count * (count - 1) / 2;
            }
        }

        long long distinct_new_strings = total_swaps - identical_char_swaps;

        long long final_distinct_count = distinct_new_strings;
        if (identical_char_swaps > 0) {
            final_distinct_count++;
        }

        return final_distinct_count;
    }
};

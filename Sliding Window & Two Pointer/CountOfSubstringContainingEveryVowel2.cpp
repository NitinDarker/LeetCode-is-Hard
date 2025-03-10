// https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/?envType=daily-question&envId=2025-03-10
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
    long long atLeastK(string word, int k) {
        unordered_map<long long, long long> vowel;
        unordered_set<char> ss = {'a', 'e', 'i', 'o', 'u'};
        long long non_vowel = 0;
        long long res = 0;
        // Using sliding Window
        int l = 0;
        for (int r = 0; r < word.length(); r++) {
            if (ss.count(word[r]) > 0) vowel[word[r]]++;
            else non_vowel++;
            while (vowel.size() == 5 && non_vowel >= k) {
                res += (word.length() - r);
                if (ss.count(word[l]) > 0) vowel[word[l]]--;
                else non_vowel--;
                if (vowel[word[l]] == 0) vowel.erase(word[l]);
                l++;
            }
        }
        return res;
    }
    
  public:
    long long countOfSubstrings(string word, int k) {
        return (long long) atLeastK(word, k) - (long long) atLeastK(word, k+1);
    }
};

// Only God knows how this shit worked.
// Don't ask me and Don't try to make sense of it. I am surprised of myself.

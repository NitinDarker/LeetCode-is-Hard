/// https://leetcode.com/problems/valid-word/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isAlphaNum(char ch) {
        return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

  public:
    bool isValid(string word) {
        if (word.length() < 3) return false;
        int vowel = 0, cons = 0;
        string vowels = "aeiouAEIOU";
        string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
        for (char ch : word) {
            if (!isAlphaNum(ch)) return false;
            if (vowels.find(ch) != vowels.npos) vowel++;
            if (consonants.find(ch) != consonants.npos) cons++;
        }
        if (vowel == 0 || cons == 0) return false;
        return true;
    }
};

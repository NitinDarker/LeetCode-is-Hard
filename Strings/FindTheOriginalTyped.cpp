/// https://leetcode.com/problems/find-the-original-typed-string-i/?envType=daily-question&envId=2025-07-01
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int possibleStringCount(string word) {
            int count = 0;
            char vis = word[0];
            for (char ch : word) {
                if (ch == vis) count++;
                else vis = ch;
            }
            return count;
        }
    };

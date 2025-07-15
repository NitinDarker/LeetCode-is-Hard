/// https://www.geeksforgeeks.org/problems/divisible-by-13/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool divby13(string &s) {
        int rem = 0;
        for (char ch : s) rem = ((rem * 10) + (ch - '0')) % 13;
        return rem == 0;
    }
};

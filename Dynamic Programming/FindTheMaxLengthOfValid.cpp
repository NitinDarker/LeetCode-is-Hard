// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumLength(vector<int> &nums) {
        // lengths of subsequences ->
        int allEven = 0; // even-even
        int allOdd = 0;  // odd-odd
        int evenOdd = 0; // even-odd
        bool flagEven = 0;
        int oddEven = 0; // odd-even
        bool flagOdd = 1;
        for (int it : nums) {
            if (it % 2 == 0) {
                allEven++;
            } else {
                allOdd++;
            }
            if (it % 2 == flagEven) {
                evenOdd++;
                flagEven = !flagEven;
            }
            if (it % 2 == flagOdd) {
                oddEven++;
                flagOdd = !flagOdd;
            }
        }
        return max(allEven, max(allOdd, max(evenOdd, oddEven)));
    }
};

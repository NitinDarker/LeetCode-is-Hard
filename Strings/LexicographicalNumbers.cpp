// https://leetcode.com/problems/lexicographical-numbers/description/?envType=daily-question&envId=2025-06-08
#include <bits/stdc++.h>
using namespace std;

class Solution {
    void helper(vector<int> &arr, int k, int n) {
        for (int i = 0; i < 10; i++) {
            int currNum = 10 * k + i;
            if (currNum > n) break;
            arr.push_back(currNum);
            helper(arr, currNum, n);
        }
        if (k >= 9 || k+1 > n) return;
        arr.push_back(k+1);
        helper(arr, k+1, n);
    }

  public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        res.push_back(1);
        helper(res, 1, n);
        return res;
    }
};

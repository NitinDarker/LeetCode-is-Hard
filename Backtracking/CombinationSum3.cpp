// https://leetcode.com/problems/combination-sum-iii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    void f (int start, int k, int n, vector<int> &arr, int currSum, vector<vector<int>> &res) {
        if (currSum == n && arr.size() == k) {
            res.push_back(arr);
            return;
        }
        if (currSum > n) return;
        if (arr.size() > k) return;
        for (int i = start; i < 10; i++) {
            arr.push_back(i);
            f(i+1, k, n, arr, currSum+i, res);
            arr.pop_back();
        }
    }

  public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> arr;
        f(1, k, n, arr, 0, res);
        return res;
    }
};

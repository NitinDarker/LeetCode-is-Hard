// https://www.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> countLessEq(vector<int> &a, vector<int> &b) {
        sort(b.begin(), b.end());
        vector<int> res;
        for (int x : a) {
            int cnt = upper_bound(b.begin(), b.end(), x) - b.begin();
            res.push_back(cnt);
        }
        return res;
    }
};

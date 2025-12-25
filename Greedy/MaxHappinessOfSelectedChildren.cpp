// https://leetcode.com/problems/maximize-happiness-of-selected-children/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());
        int cnt = 0, i = n-1;
        long long happy = 0;
        while (i >= 0 && cnt < k) {
            if (happiness[i] - cnt >= 0) {
                happy += (happiness[i] - cnt);
            }
            cnt++;
            i--;
        }
        return happy;
    }
};

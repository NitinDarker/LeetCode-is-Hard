// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/?envType=daily-question&envId=2025-06-14
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minMaxDifference(int num) {
        vector<int> arr;
        while (num > 0) {
            arr.push_back(num % 10);
            num /= 10;
        }

        int it = arr.size() - 1;
        int msd9 = arr[it], msd0 = arr[it]; // Most significant digit
        while (msd9 == 9 && it > 0) {
            it--;
            msd9 = arr[it];
        }
        it = arr.size() - 1;
        while (msd0 == 0 && it > 0) {
            it--;
            msd0 = arr[it];
        }
        int maxNum = 0, minNum = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] == msd9) {
                maxNum = maxNum * 10 + 9;
            } else {
                maxNum = maxNum * 10 + arr[i];
            }
            if (arr[i] == msd0) {
                minNum = minNum * 10 + 0;
            } else {
                minNum = minNum * 10 + arr[i];
            }
        }
        return maxNum - minNum;
    }
};

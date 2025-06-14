// https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxDiff(int num) {
        vector<int> arr;
        while (num > 0) {
            arr.push_back(num % 10);
            num /= 10;
        }
        int n = arr.size();

        int it = n - 1;
        int msd9 = arr[it]; // Most significant digit
        int msd0 = arr[it];
        while (msd9 == 9 && it > 0) {
            it--;
            msd9 = arr[it];
        }

        it = n - 1;
        if (msd0 == 1) {
            it--;
            msd0 = arr[it];
        }
        while (msd0 == 0 && it > 0) {
            it--;
            msd0 = arr[it];
        }

        bool replaceByOne = false;
        if (msd0 == 1 && it == n - 2) { // Special Case
            while (it > 0 && (msd0 == 1 || msd0 == 0)) {
                it--;
                msd0 = arr[it];
            }
            if (it == 0 && msd0 == 0) {
                replaceByOne = false;
            } else if (it == 0 && msd0 == 1) {
                replaceByOne = true;
            } else {
                replaceByOne = false;
            }
            if (it == 0) it--;
        }

        if (it == 0 && msd0 == 0) {
            replaceByOne = false;
        } else if (it == 0 && msd0 != 0) {
            replaceByOne = true;
        } else if (it == n - 1) {
            replaceByOne = true;
        } else if (msd0 > 1 && it == n - 2) {
            replaceByOne = false;
        } else if (msd0 == 1 && it == n - 1) {
            replaceByOne = true;
            while (it > 0) {
                it--;
                msd0 = arr[it];
            }
        }

        int maxNum = 0, minNum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] == msd9) {
                maxNum = maxNum * 10 + 9;
            } else {
                maxNum = maxNum * 10 + arr[i];
            }
            if (arr[i] == msd0) {
                if (replaceByOne)
                    minNum = minNum * 10 + 1;
                else
                    minNum = minNum * 10 + 0;
            } else {
                minNum = minNum * 10 + arr[i];
            }
        }
        return maxNum - minNum;
    }
};

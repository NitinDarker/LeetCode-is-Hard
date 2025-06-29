// https://leetcode.com/problems/split-array-largest-sum/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(int k, long long maxSum, vector<int> &nums) {
        int count = 1;
        long long currSum = 0;
        for (long long ele : nums) {
            if (ele + currSum > maxSum) {
                count++;
                currSum = ele;
            } else {
                currSum += ele;
            }
            if (count > k) return false;
        }
        return true;
    }

  public:
    int splitArray(vector<int> &nums, int k) {
        int sum = 0;
        int maxi = nums[0];
        for (int ele : nums) {
            sum += ele;
            maxi = max(maxi, ele);
        }

        int low = maxi, high = sum;
        int res = high;

        while (low <= high) {
            int mid = low + ((high - low)/2);
            if (isPossible(k, mid, nums)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};

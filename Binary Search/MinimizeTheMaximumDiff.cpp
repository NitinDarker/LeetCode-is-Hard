// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/?envType=daily-question&envId=2025-06-13
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int countPairs(vector<int> &nums, int maxDiff) {
        int i = 0;
        int count = 0;
        while (i < nums.size() - 1) {
            int diff = nums[i+1] - nums[i];
            if (diff <= maxDiff) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        return count;
    }
    
  public:
    int minimizeMax(vector<int> &nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums[nums.size() - 1] - nums[0];
        while (low <= high) {
            int mid = low + ((high - low)/2);
            if (countPairs(nums, mid) < p) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

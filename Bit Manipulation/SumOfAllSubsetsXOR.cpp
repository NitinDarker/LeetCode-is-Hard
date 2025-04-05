// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2025-04-05
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int subsetXORSum(vector<int> &nums) {
        int xorSum = 0;
        for (int num : nums) xorSum ^= num;
        return xorSum * (1 << (nums.size()-1));
    }
};

class Solution3 {
    void dfs(int ind, int xorSum, int &finalSum, vector<int> &nums) {
        if (ind == nums.size()) {
            finalSum += xorSum;
            return;
        }
        dfs(ind+1, xorSum^nums[ind], finalSum, nums); // Take
        dfs(ind+1, xorSum, finalSum, nums); // Not take
    }

  public:
    int subsetXORSum(vector<int> &nums) {
        int finalSum = 0;
        dfs(0, 0, finalSum, nums);
        return finalSum;
    }
};

class Solution2 {
  public:
    int subsetXORSum(vector<int> &nums) {
        int limit = 1 << nums.size(); // Not inclusive
        int comb = 0;
        int xorSum = 0;
        while (comb < limit) {
            int currComb = comb;
            int currSum = 0;
            for (int ele : nums) {
                if (currComb & 1) currSum ^= ele;
                currComb = currComb >> 1;
            }
            xorSum += currSum;
            comb += 1;
        }
        return xorSum;
    }
};

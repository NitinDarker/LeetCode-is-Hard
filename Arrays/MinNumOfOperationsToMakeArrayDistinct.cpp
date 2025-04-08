// https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumOperations(vector<int> &nums) {
        unordered_map<int, int> freq;
        unordered_set<int> targetNums;
        for (int num : nums) {
            if (freq.find(num) != freq.end()) {
                targetNums.insert(num);
            }
            freq[num]++;
        }
        int opCount = 0;
        int start = 0; // Pointer pointing start of the array
        while (targetNums.size() > 0) {
            for (int i = start; i < start + 3; i++) {
                if (i == nums.size())
                    break;
                if (freq[nums[i]] == 1) {
                    freq[nums[i]] = 0;
                } else if (freq[nums[i]] == 2) {
                    freq[nums[i]]--;
                    targetNums.erase(nums[i]);
                } else {
                    freq[nums[i]]--;
                }
            }
            opCount++;
            start += 3;
        }
        return opCount;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumOperations(vector<int> &nums) {
        unordered_map<int, int> freq;
        unordered_set<int> targetNums;
        for (int num : nums) {
            if (freq.find(num) != freq.end()) {
                targetNums.insert(num);
            }
            freq[num]++;
        }
        int opCount = 0;
        int start = 0; // Pointer pointing start of the array
        while (targetNums.size() > 0) {
            for (int i = start; i < start + 3; i++) {
                if (i == nums.size())
                    break;
                if (freq[nums[i]] == 1) {
                    freq[nums[i]] = 0;
                } else if (freq[nums[i]] == 2) {
                    freq[nums[i]]--;
                    targetNums.erase(nums[i]);
                } else {
                    freq[nums[i]]--;
                }
            }
            opCount++;
            start += 3;
        }
        return opCount;
    }
};

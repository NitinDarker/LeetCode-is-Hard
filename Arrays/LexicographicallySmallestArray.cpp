/* 2948. Make Lexicographically Smallest Array by Swapping Elements -> LeetCode Daily Problem

You are given a 0-indexed array of positive integers nums and a positive integer limit.

In one operation, you can choose any two indices i and j and swap nums[i] and nums[j]
if |nums[i] - nums[j]| <= limit.

Return the lexicographically smallest array that can be obtained by 
performing the operation any number of times.

An array a is lexicographically smaller than an array b if 
in the first position where a and b differ, array a has an element that is 
less than the corresponding element in b. 
For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3]
 because they differ at index 0 and 2 < 10.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> arr(nums.begin(), nums.end());
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        vector<queue<int>> groups;
        unordered_map<int, int> mpp;
        
        queue<int> g1;
        g1.push(arr[0]);
        groups.push_back(g1);
        int ind = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i-1] <= limit) {
                groups[ind].push(arr[i]);
                mpp[arr[i]] = ind;
            } else {
                queue<int> g2;
                g2.push(arr[i]);
                groups.push_back(g2);
                ind++;
                mpp[arr[i]] = ind;
            }
        }

        for (int &num: nums) {
            ind = mpp[num];
            num = groups[ind].front();
            groups[ind].pop();
        }
        return nums;
    }
};

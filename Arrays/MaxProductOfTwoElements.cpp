// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int n = nums.size();
            int largest = nums[0];
            int second = 0;
            for (int i = 1; i < n; i++) {
                int ele = nums[i];
                if (ele > largest) {
                    second = largest;
                    largest = ele;
                } else if (ele > second) {
                    second = ele;
                } else {
                    continue;
                }
            }
            return (largest - 1) * (second - 1);

        }
    };

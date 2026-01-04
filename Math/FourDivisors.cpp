// https://leetcode.com/problems/four-divisors/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int fourFactorSum(int num) {
        int sum = 0;
        int divCount = 0;
        for (int fact = 1; fact*fact <= num; fact++) {
            if (num % fact == 0) {
                sum += fact;
                sum += (num/fact);
                if (fact == (num/fact)) divCount += 1;
                else divCount += 2;
            } 
            if (divCount > 4) break;
        }
        if (divCount == 4) return sum;
        else return 0;
    }

  public:
    int sumFourDivisors(vector<int> &nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += fourFactorSum(nums[i]);
        }
        return sum;
    }
};

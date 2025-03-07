// https://leetcode.com/problems/closest-prime-numbers-in-range/description/?envType=daily-question&envId=2025-03-07
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
    vector<bool> findPrimes(int limit) {
        // Using Sieve of Eratosthenes
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false;
        int p = 2;
        while (p * p <= limit) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
            p++;
            while (p <= limit && isPrime[p] == false) {
                p++;
            }
        }
        return isPrime;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> primes = findPrimes(right);
        vector<int> nums;
        for (int i = left; i < primes.size(); i++) {
            if (primes[i]) {
                nums.push_back(i);
            }
        }
        if (nums.size() < 2) {
            return {-1, -1};
        }
        int minDiff = INT_MAX;
        int num1 = -1, num2 = -1;
        int l = 0, r = 1;
        while (r < nums.size()) {
            int diff = nums[r] - nums[l];
            if (diff < minDiff) {
                num1 = nums[l];
                num2 = nums[r];
                minDiff = diff;
            }
            l++;
            r++;
        }
        return {num1, num2};
    }
};

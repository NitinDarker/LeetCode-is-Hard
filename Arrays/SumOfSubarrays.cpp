// https://www.geeksforgeeks.org/problems/sum-of-subarrays2229/1
#include <bits/stdc++.h>
using namespace std;

// O(n^2)
class Solution {
  public:
    int subarraySum(vector<int> &arr) {
        int n = arr.size();
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = arr[i] + prefix[i-1];
        }
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += prefix[i];
            for (int j = 0; j < i; j++) {
                totalSum += (prefix[i] - prefix[j]);
            }
        }
        return totalSum;
    }
};

// O(n)
class Solution {
  public:
    int subarraySum(vector<int> &arr) {
        int n = arr.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            // Number of subarrays that include arr[i]
            totalSum += arr[i] * (i+1) * (n-i);
        }
        return totalSum;
    }
};

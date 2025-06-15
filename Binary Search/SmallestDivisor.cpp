// https://www.geeksforgeeks.org/problems/smallest-divisor/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int calc(double div, const vector<int> &arr) {
        double sum = 0;
        for (double ele : arr) {
            sum += ceil(ele / div);
        }
        return (int)sum;
    }

  public:
    int smallestDivisor(vector<int> &arr, int k) {
        int maxElement = *max_element(arr.begin(), arr.end());
        int low = 1, high = maxElement;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (calc(mid, arr) > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

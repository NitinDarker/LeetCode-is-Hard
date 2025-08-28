// https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxOnes(vector<int> &arr, int k) {
        int n = arr.size();
        int maxSize = 0;
        int i = 0, j = 0;
        while (j < n) {
            if (arr[j] == 0 && k > 0) {
                k--;
                j++;
            } else if (arr[j] == 1) {
                j++;
            } else { 
                if (arr[i] == 0) {
                    k++;
                }
                i++;
            }
            maxSize = max(maxSize, j-i);
        }
        maxSize = max(maxSize, j-i);
        return maxSize;
    }
};

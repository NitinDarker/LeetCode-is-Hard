// https://www.geeksforgeeks.org/problems/count-elements-less-than-or-equal-to-k-in-a-sorted-rotated-array/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countLessEqual(vector<int> &arr, int x) {
        int pivot = 0;
        int n = arr.size();
        int small = arr[0];
        for (int i = 0; i < n; i++) {
            if (arr[i] < small) {
                pivot = i;
                break;
            }
        }
        int cnt = 0;
        cnt += (upper_bound(arr.begin(), arr.begin()+pivot, x) - arr.begin());
        cnt += (upper_bound(arr.begin()+pivot, arr.end(), x) - (arr.begin()+pivot));
        return cnt;
    }
};

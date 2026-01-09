// https://www.geeksforgeeks.org/problems/subarrays-with-at-most-k-distinct-integers/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq;
        int l = 0, r = 0, cnt = 0;
        while (r < n) {
            freq[arr[r]]++;
            while (freq.size() > k) {
                freq[arr[l]]--;
                if (freq[arr[l]] == 0) freq.erase(arr[l]);
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
};

// https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq;
        vector<int> res;
        int l = 0, r = 0;
        while (r < k) {
            freq[arr[r]]++;
            r++;
        }
        res.push_back(freq.size());
        while (r < n) {
            freq[arr[r]]++;
            freq[arr[l]]--;
            if (freq[arr[l]] == 0) freq.erase(arr[l]);
            res.push_back(freq.size());
            l++;
            r++;
        }
        return res;
    }
};

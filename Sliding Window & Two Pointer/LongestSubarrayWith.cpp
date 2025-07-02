/// https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int, int> mpp;
        int i = 0, j = 0;
        int maxLength = 0;
        int curr = 0;
        while (j < n) {
            mpp[arr[j]]++;
            if (mpp.size() > 2) {
                mpp[arr[i]]--;
                if (mpp[arr[i]] == 0) {
                    mpp.erase(arr[i]);
                }
                i++;
                curr--;
                mpp[arr[j]]--; // Counter Measure -> Not good
            } else {
                j++;
                curr++;
            }  
            maxLength = max(maxLength, curr);
        }
    }
};

// https://www.geeksforgeeks.org/problems/koko-eating-bananas/1
// https://leetcode.com/problems/koko-eating-bananas/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int eatingTime(const vector<int> &arr, int s) {
        int time = 0;
        for (int i = 0; i < arr.size(); i++) {
            time += ceil((double)arr[i] / (double)s); 
        }
        return time;
    }

    int maxElement(vector<int> &arr) {
        int maxi = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }

  public:
    int kokoEat(vector<int> &arr, int k) {
        int low = 1, high = maxElement(arr);
        while (low < high) {
            int mid = low + ((high - low) / 2);
            int time = eatingTime(arr, mid);
            if (time > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

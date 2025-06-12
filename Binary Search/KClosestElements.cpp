// https://www.geeksforgeeks.org/problems/k-closest-elements3619/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int binarySearch(vector<int> arr, int x) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (arr[mid] == x) return mid;
            else if (arr[mid] > x) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }

  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        int count = 0;
        vector<int> res;
        
        int idx = binarySearch(arr, x);

        int i = idx - 1, j = idx + 1;
        if (idx == -1) {
            for (int q = 0; q < arr.size(); q++) {
                if (arr[q] > x) {
                    i = q - 1;
                    j = q;
                    break;
                }
            }
            if (i < 0) i = arr.size() - 1;
        }

        while (count != k) {
            int left = INT_MAX, right = INT_MAX;
            if (i >= 0) left = abs(arr[i] - x);
            if (j < arr.size()) right = abs(arr[j] -x);
            if (left < right) {
                count++;
                res.push_back(arr[i]);
                i--;
            } else if (left > right) {
                count++;
                res.push_back(arr[j]);
                j++;
            } else {
                count++;
                res.push_back(max(arr[i], arr[j]));
                if (arr[i] > arr[j]) i--;
                else j++;
            }
        }
        return res;
    }
};

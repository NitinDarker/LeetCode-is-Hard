// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int> &arr, vector<int> &dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int count = 0; // Platform Counter
        int maxi = 0;  // Max Platforms
        int a = 0;     // Arrival Pointer
        int d = 0;     // Departure Pointer

        while (a < n) {
            if (arr[a] <= dep[d]) {
                count++;
                a++;
            } else {
                d++;
                count--;
            }
            if (count > maxi) maxi = count;
        }
        return maxi;
    }
};

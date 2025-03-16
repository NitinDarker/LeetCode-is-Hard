// https://leetcode.com/problems/minimum-time-to-repair-cars/description/?envType=daily-question&envId=2025-03-16
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
    bool isPossible(vector<int> ranks, int cars, long long time) {
        // cars = sqrt(time / rank)
        long long currCars = 0;
        for (int rank: ranks) {
            currCars += (long long) sqrt(time / (long long) rank);
            if (currCars >= cars) return true;
        }
        if (currCars < cars) return false;
        return true;
    }

  public:
    long long repairCars(vector<int> &ranks, int cars) {
        int total = ranks.size();
        sort(ranks.begin(), ranks.end());
        //  time = r * n^2 minutes.
        long long low = 1;
        long long high = (long long) ranks[0] * (long long) cars * (long long) cars;
        long long minTime = high;
        while (low <= high) {
            long long mid = low + ((high-low)/2);
            if (isPossible(ranks, cars, mid)) {
                minTime = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return minTime;
    }
};

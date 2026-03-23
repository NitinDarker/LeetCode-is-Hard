// https://leetcode.com/problems/car-fleet/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        int n = position.size();
        vector<vector<int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end(), greater<vector<int>>());

        int cnt = 1;
        double lastTime = (target - cars[0][0]) / (double)cars[0][1];
        for (int i = 1; i < n; i++) {
            double time = (target - cars[i][0]) / (double)cars[i][1];
            if (time > lastTime) {
                cnt++;
                lastTime = time;
            }
        }
        return cnt;
    }
};

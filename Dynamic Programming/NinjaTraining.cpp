// https://www.geeksforgeeks.org/problems/geeks-training/1
#include <bits/stdc++.h>
using namespace std;

// Memoization -> Top-Down Approach (Recursion + DP)
int findMaxPoints(int day, int last, vector<vector<int>> &dp, const vector<vector<int>> &arr) {
    if (day == -1) return 0;
    if (dp[day][last] != -1) return dp[day][last];
    int maxi = 0;
    for (int i = 0; i < 3; i++) {
        if (i != last) {
            int points = arr[day][i] + findMaxPoints(day - 1, i, dp, arr);
            maxi = max(maxi, points);
        }
    }
    dp[day][last] = maxi;
    return maxi;
}

// Tabulation -> Bottom-Up Approach (Iterative) 
int maxPointsTab(vector<vector<int>> &points) {
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for (int task = 0; task <= 2; task++) {
                if (task != last) {
                    // Calculate the points for the current activity and add it to the
                    // maximum points obtained on the previous day (recursively calculated)
                    int activity = points[day][task] + dp[day - 1][task];
                    // Update the maximum points for the current day and last activity
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }
    return dp[n - 1][3];
}

int ninjaTraining(vector<vector<int>> &arr) {
    vector<vector<int>> dp(arr.size(), vector<int>(4, -1)); // DP Array
    return findMaxPoints(arr.size() - 1, 3, dp, arr);
}

int main() {
    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};
    cout << ninjaTraining(points);
}

// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    int maxScore(vector<int> &cardPoints, int k) {
        int total = 0; // Total points of all cards
        for (int ele: cardPoints) {
            total += ele;
        }

        int n = cardPoints.size(); // Number of cards
        int size = n - k; // Size of sliding window/sub-array
        // Remove a sub-array from cardPoints with length n - k to find score

        int l = 0, r = size;
        int windowPoints = 0;
        for (int i = l; i < r; i++) {
            windowPoints += cardPoints[i];
        }

        int currScore = total - windowPoints;
        int finalScore = currScore;
        while (r < n) {
            windowPoints -= cardPoints[l];
            windowPoints += cardPoints[r];
            l++;
            r++;
            currScore = total - windowPoints;
            if (currScore > finalScore) finalScore = currScore;
        }
        return finalScore;
    }
};

// https://leetcode.com/problems/minimum-penalty-for-a-shop/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int penalty = 0;
        for (char ch : customers) {
            if (ch == 'Y') penalty++;
        }
        int mini = 0, minPenalty = penalty;
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y') penalty--;
            else penalty++;
            if (penalty < minPenalty) {
                minPenalty = penalty;
                mini = i+1;
            }
        }
        return mini;
    }
};

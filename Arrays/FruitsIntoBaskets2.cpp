// https://leetcode.com/contest/weekly-contest-440/problems/fruits-into-baskets-ii/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
        int count = 0;
        for (int i = 0; i < fruits.size(); i++) {
            bool unplaced = true;
            for (int j = 0; j < baskets.size(); j++) {
                if (baskets[j] >= fruits[i]) {
                    baskets[j] = -1;
                    unplaced = false;
                    break;
                }
            }
            if (unplaced) count++;
        }
        return count;
    }
};

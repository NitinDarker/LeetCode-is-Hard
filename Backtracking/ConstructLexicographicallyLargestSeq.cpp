// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/?envType=daily-question&envId=2025-02-16
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
    bool backtrack(int ind, vector<int> &arr, unordered_set<int> &mpp, int n) {
        int size = arr.size();
        if (ind == size) return true;
        for (int num = n; num > 0; num--) {
            if (mpp.find(num) != mpp.end()) continue;
            if (num > 1 && (ind+num >= size || arr[ind+num] != 0)) continue;

            // Recursive step
            mpp.insert(num);
            arr[ind] = num;
            if (num > 1) arr[ind+num] = num;
            
            int j = ind+1;
            while (j < size && arr[j] != 0) j++;

            if(backtrack(j, arr, mpp, n)) return true;

            // Backtracking step
            mpp.erase(num);
            arr[ind] = 0;
            if (num > 1) arr[ind+num] = 0;
        }
        return false;
    }

  public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> arr(2*n-1, 0); // To store the sequence
        unordered_set<int> mpp; // Stores the used keys

        backtrack(0, arr, mpp, n);
        return arr;
    }
};

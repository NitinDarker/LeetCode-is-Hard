/// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/?envType=daily-question&envId=2025-07-06
#include <bits/stdc++.h>
using namespace std;

class FindSumPairs {
    vector<int> a, b;
    unordered_map<int, int> mpp;

  public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2) {
        a = nums1, b = nums2;
        for (int ele : nums2) {
            mpp[ele]++;
        }
    }

    void add(int index, int val) {
        mpp[b[index]]--;
        b[index] += val;
        mpp[b[index]]++;
    }

    int count(int tot) {
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            if (mpp.find(tot-a[i]) != mpp.end()) {
                res += mpp[tot-a[i]];
            }
        }
        return res;
    }
};

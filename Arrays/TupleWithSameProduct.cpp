// https://leetcode.com/problems/tuple-with-same-product/description/?envType=daily-question&envId=2025-02-06

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> mpp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mpp[nums[i] * nums[j]]++;
            }
        }
        int count = 0;
        for (auto mul: mpp) {
            if (mul.first < 2) {
                continue;
            }
            count += mul.second * (mul.second - 1) * 4;
        }
        return count;
    }
};

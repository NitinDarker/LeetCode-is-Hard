// https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/
class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        int n = arr.size();
        int cnt = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (mpp.find(sum - k) != mpp.end()) {
                cnt += mpp[sum-k];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};

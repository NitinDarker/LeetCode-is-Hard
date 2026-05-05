// https://www.geeksforgeeks.org/problems/sum-of-xor-of-all-pairs0723/1
class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        int n = arr.size();
        long long res = 0;
        for (int i = 0; i < 32; i++) {
            long long count1 = 0;
            for (int num : arr) {
                if ((num & (1 << i)) != 0) count1++;
            }
            long long count0 = n - count1;
            res += count1 * count0 * (1LL << i);
        }
        return res;
    }
};

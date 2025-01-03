class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> arr(n, 1);
        int mod = 1e9 + 7;
        for (int j = 0; j < k; j++) {
            for (int i = 1; i < n; i++) {
                arr[i] = (arr[i] + arr[i-1]) % (mod);
            }
        }
        return arr[n-1];
    }
};
// Not optimized

https://leetcode.com/problems/number-complement/
class Solution {
public:
    int findComplement(int n) {
        int temp = n;
        int pos = 0;
        while (temp > 0) {
            temp >>= 1;
            pos++;
        }
        int res = 0;
        for (int i = 0; i < pos; i++) {
            int bit = !((1 << i) & n);
            res = ((bit << i) | res);
        }
        return res;
    }
};

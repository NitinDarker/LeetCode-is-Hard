// https://leetcode.com/problems/count-symmetric-integers/

/* You are given two positive integers low and high.

An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.

Return the number of symmetric integers in the range [low, high].
*/

class Solution {
  public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            int num = i;
            if (num <= 9 || (num >= 100 && num <= 999) || (num == 10000)) {
                continue;
            }
            if (num >= 10 && num <= 99) {
                int right = num % 10;
                num /= 10;
                int left = num;
                count = (left == right ? count + 1 : count);
            } else {
                int rightSum = 0;
                rightSum += num % 10;
                num /= 10;
                rightSum += num % 10;
                num /= 10;
                int leftSum = 0;
                leftSum += num % 10;
                num /= 10;
                leftSum += num;
                count = (leftSum == rightSum ? count + 1 : count);
            }
        }
        return count;
    }
};
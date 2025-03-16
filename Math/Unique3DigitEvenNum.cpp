// https://leetcode.com/contest/biweekly-contest-152/problems/unique-3-digit-even-numbers/
class Solution {
  public:
    int totalNumbers(vector<int> &digits) {
        set<int> uniqueNumbers;
        int n = digits.size();
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0)
                continue;
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j)
                        continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num % 2 == 0) {
                        uniqueNumbers.insert(num);
                    }
                }
            }
        }
        return uniqueNumbers.size();
    }
};

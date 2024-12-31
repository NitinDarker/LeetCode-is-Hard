class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0, ten = 0, twenty = 0;
        for (int i: bills) {
            if (i == 5) {
                five++;
                continue;
            } else if (i == 10) {
                if (five == 0) return false;
                ten++;
                five--;
            } else {
                if ((five < 3) && (five == 0 || ten == 0)) return false;
                twenty++;
                if (ten != 0) {
                    ten--;
                    five--;
                } else {
                    five -= 3;
                }
            }
        }
        return true;
    }
};

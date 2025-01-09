// 645. Set Mismatch

// You have a set of integers s, which originally contains all the numbers from 1 to n. 
// Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
// which results in repetition of one number and loss of another number.
// You are given an integer array nums representing the data status of this set after the error.
// Find the number that occurs twice and the number that is missing and return them in the form of an array.

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> s;
        int twice = -1;
        int missing = -1;
        for (int i: nums) {
            if (s.find(i) != s.end()) {
                twice = i;
            }
            s.insert(i);
        }
        int i = 0;
        for (int ele: s) {
            if (ele != i+1) {
                missing = i+1;
                break;
            }
            i++;
        }
        if (missing == -1) missing = i+1;
        return {twice, missing};
    }
};

/* 1769. Minimum Number of Operations to Move All Balls to Each Box - LeetCode Daily Problem

You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.
In one operation, you can move one ball from a box to an adjacent box. 
Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.
Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.
Each answer[i] is calculated considering the initial state of the boxes.
*/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> ans(n, 0);
        int balls = 0, moves = 0;
        for (int i = 0; i < n; i++) {
            ans[i] += balls + moves;
            moves += balls;
            if (boxes[i] == '1') balls++;
        }
        balls = 0; moves = 0;
        for (int i = n-1; i >= 0; i--) {
            ans[i] += balls + moves;
            moves += balls;
            if (boxes[i] == '1') balls++;
        }
        return ans;
    }
};

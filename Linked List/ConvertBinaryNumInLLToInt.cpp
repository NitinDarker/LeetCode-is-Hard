// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
class Solution {
  public:
    int getDecimalValue(ListNode *head) {
        ListNode *temp = head;
        int res = 0;
        while (temp != NULL) {
            res = (res << 1) | temp->val;
            temp = temp->next;
        }
        return res;
    }
};

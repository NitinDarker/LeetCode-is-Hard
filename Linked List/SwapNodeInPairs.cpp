// https://leetcode.com/problems/swap-nodes-in-pairs/
class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *dHead = new ListNode(-1, head);
        ListNode *temp0 = dHead;
        while (true) {
            ListNode *temp1 = temp0->next;
            if (temp1 == NULL) break;
            ListNode *temp2 = temp1->next;
            if (temp2 == NULL) break;
            temp0->next = temp2;
            temp1->next = temp2->next;
            temp2->next = temp1;
            temp0 = temp1;
        }
        return dHead->next;
    }
};

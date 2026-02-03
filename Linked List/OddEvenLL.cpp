// https://leetcode.com/problems/odd-even-linked-list/
class Solution {
  public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next || !head->next->next) return head;
        ListNode *evenHead = head->next;
        ListNode *prev = head, *cur = head->next;
        while (cur && cur->next) {
            ListNode *ahead = cur->next;
            prev->next = cur->next;
            cur->next = ahead->next;
            prev = ahead;
            cur = ahead->next;
        }
        prev->next = evenHead;
        return head;
    }
};

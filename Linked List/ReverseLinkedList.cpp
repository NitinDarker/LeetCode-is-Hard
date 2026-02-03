// https://leetcode.com/problems/reverse-linked-list/
class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *prev = nullptr, *cur = head;
        while(cur != nullptr) {
            ListNode *ahead = cur->next;
            cur->next = prev;
            prev = cur;
            cur = ahead;
        }
        return prev;
    }
};

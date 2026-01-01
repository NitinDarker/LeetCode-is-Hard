// https://leetcode.com/problems/intersection-of-two-linked-lists/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a->next;
            b = b->next;
            if (a == NULL && b == NULL) break;
            if (a == NULL) a = headB;
            if (b == NULL) b = headA;
        }
        return a;
    }
};

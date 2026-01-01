// https://leetcode.com/problems/intersection-of-two-linked-lists/
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode a = headA, b = headB;
        while (a != b) {
            a = a.next;
            b = b.next;
            if (a == null && b == null) break;
            if (a == null) a = headB;
            if (b == null) b = headA;
        }
        return a;
    }
}

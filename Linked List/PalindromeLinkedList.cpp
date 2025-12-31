// https://leetcode.com/problems/palindrome-linked-list/
class Solution {
    ListNode *reverse(ListNode *head) {
        ListNode *rev = NULL;
        ListNode *ptr = head;
        while (ptr != NULL) {
            ListNode *newNode = new ListNode(ptr->val);
            newNode->next = rev;
            rev = newNode;
            ptr = ptr->next;
        }
        return rev;
    }
    
  public:
    bool isPalindrome(ListNode *head) {
        ListNode *rev = reverse(head);

        ListNode *l = head, *r = rev;
        while (l != NULL) {
            if (l->val != r->val) {
                return false;
            }
            l = l->next;
            r = r->next;
        }
        return true;
    }
};

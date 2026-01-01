// https://leetcode.com/problems/palindrome-linked-list/
#include <bits/stdc++.h>
using namespace std;

class ListNode {
  public:
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
    ListNode *reverse(ListNode *mid) {
        ListNode *prev = NULL;
        ListNode *curr = mid;
        while (curr != NULL) {
            ListNode *ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        return prev;
    }
    
  public:
    bool isPalindrome(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *tail = reverse(slow);
        ListNode *l = head, *r = tail;
        while (r != slow) {
            if (l->val != r->val) return false;
            l = l->next;
            r = r->next;
        }
        return l->val == r->val;
    }
};

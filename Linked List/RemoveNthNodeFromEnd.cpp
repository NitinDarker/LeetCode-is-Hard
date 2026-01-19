// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = dummy;
        for (int i = 0; i < n; i++) p = p->next;
        ListNode *q = dummy;
        while (p->next != NULL) {
            p = p->next;
            q = q->next;
        }
        // Now q is pointing to node before the target
        ListNode *target = q->next;
        q->next = target->next;
        delete target;
        return dummy->next;
    }
};

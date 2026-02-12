// https://leetcode.com/problems/reorder-list/
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
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        return prev;
    }

  public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;

        // Find Middle Node
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }   

        // Reverse second half
        ListNode *head2 = slow->next;
        slow->next = nullptr;
        head2 = reverseList(head2);

        // Merge alternately
        ListNode *temp = head;
        ListNode *p = head->next, *q = head2;
        while (p && q) {
            temp->next = q;
            q = q->next;
            temp = temp->next;
            temp->next = p;
            p = p->next;
            temp = temp->next;
        }
        if (p) temp->next = p;
        if (q) temp->next = q;
    }
};

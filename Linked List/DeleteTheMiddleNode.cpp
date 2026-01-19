// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
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
    ListNode *deleteMiddle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *slow = dummy;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = slow->next;
        slow->next = mid->next;
        delete mid;
        return dummy->next;
    }
};

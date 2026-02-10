// https://leetcode.com/problems/merge-two-sorted-lists/description/
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *dHead = new ListNode(-1);
        ListNode *cur = dHead;
        ListNode *p = list1, *q = list2;
        while (p && q) {
            if (p->val < q->val) {
                cur->next = p;
                p = p->next;
            } else {
                cur->next = q;
                q = q->next;
            }
            cur = cur->next;
        }
        if (p) cur->next = p;
        if (q) cur->next = q;
        ListNode *merged = dHead->next;
        delete dHead;
        return merged;
    }
};

// https://leetcode.com/problems/partition-list/
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
    ListNode *partition(ListNode *head, int x) {
        if (!head || !head->next) return head;
        ListNode *lowHead = new ListNode(-1);
        ListNode *highHead = new ListNode(-1);
        ListNode *l = lowHead, *h = highHead;
        ListNode *cur = head;
        while (cur != nullptr) {
            if (cur->val < x) {
                l->next = cur;
                l = l->next;
            } else {
                h->next = cur;
                h = h->next;
            }
            cur = cur->next;
        }
        l->next = highHead->next;
        h->next = nullptr;
        ListNode *res = lowHead->next;
        delete lowHead; 
        delete highHead;
        return res;
    }
};

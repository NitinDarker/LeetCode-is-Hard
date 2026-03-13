// https://leetcode.com/problems/reverse-linked-list-ii/description/
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
    ListNode* reverse(ListNode *head, ListNode *tail) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur != tail) {
            ListNode *ahead = cur->next;
            cur->next = prev;
            prev = cur;
            cur = ahead;
        }
        return prev;
    }

  public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (!head || !head->next) return head;
        ListNode *prevStart = nullptr, *start = head;
        int cnt = 1;
        while (cnt < left) {
            prevStart = start;
            start = start->next;
            cnt++;
        }
        ListNode *end = start;
        while (cnt < right) {
            end = end->next;
            cnt++;
        }
        ListNode *endNext = end->next;
        ListNode *rev = reverse(start, endNext);
        if (prevStart) prevStart->next = rev;
        start->next = endNext;
        if (left == 1) return rev;
        return head;
    }
};

// https://leetcode.com/problems/rotate-list/description/
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
    int lengthOfLL(ListNode *head) {
        int size = 0;
        ListNode *cur = head;
        while (cur) size++, cur = cur->next;
        return size;
    }

  public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next) return head;
        int n = lengthOfLL(head);
        k = k % n;
        if (k == 0) return head;
        
        // Find kth Node from end
        int cnt = 0;
        ListNode *r = head;
        while (cnt < k) cnt++, r = r->next;
        ListNode *l = head;
        while (r->next) r = r->next, l = l->next;

        ListNode *newHead = l->next;
        l->next = nullptr;
        r->next = head;
        return newHead;
    }
};

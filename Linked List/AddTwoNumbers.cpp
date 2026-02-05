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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p = l1, *q = l2;
        ListNode *tail = nullptr;
        int carry = 0;
        while (p && q) {
            int sum = p->val + q->val + carry;
            carry = sum / 10;
            p->val = sum % 10;
            if (p->next == nullptr) tail = p;
            p = p->next;
            q = q->next;
        }
        while (p && carry) {
            int sum = p->val + carry;
            carry = sum / 10;
            p->val = sum % 10;
            if (p->next == nullptr) tail = p;
            p = p->next;
        } 
        if (q) tail->next = q;
        while (q && carry) {
            int sum = q->val + carry;
            carry = sum / 10;
            q->val = sum % 10;
            if (q->next == nullptr) tail = q;
            q = q->next;
        }
        if (carry) tail->next = new ListNode(1);
        return l1;
    }
};

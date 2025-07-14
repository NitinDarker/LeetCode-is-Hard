/// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Recursion
class Solution1 {
    void f(ListNode *node, long long &power, long long &deci) {
        if (node == NULL) return;
        f(node->next, power, deci);
        deci += node->val * power;
        power *= 2;
    }

  public:
    int getDecimalValue(ListNode *head) {
        long long power = 1, deci = 0;
        f(head, power, deci);
        return deci;
    }
};

// Bit Manipulation
class Solution {
  public:
    int getDecimalValue(ListNode *head) {
        ListNode *temp = head;
        int res = 0;
        while (temp != NULL) {
            res = (res << 1) | temp->val;
            temp = temp->next;
        }
        return res;
    }
};

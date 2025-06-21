// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *prev = head;
        ListNode *curr = head->next;
        while (curr != NULL) {
            if (prev->val == curr->val) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                continue;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};

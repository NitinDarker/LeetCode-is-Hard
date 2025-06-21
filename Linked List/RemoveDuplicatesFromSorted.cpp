// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
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
        if (head == NULL || head->next == NULL) return head;
        unordered_map<int, int> freq;
        ListNode *curr = head;
        while (curr != NULL) {
            freq[curr->val]++;
            curr = curr->next;
        }
        ListNode *prev = head;
        while (prev != NULL && freq[prev->val] > 1) {
            curr = prev;
            prev = prev->next;
            delete curr;
        }
        ListNode *newHead = prev;
        if (newHead == NULL) return newHead;
        curr = prev->next;
        while (curr != NULL) {
            if (freq[curr->val] > 1) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                continue;
            }
            prev = curr;
            curr = curr->next;
        }
        return newHead;
    }
};

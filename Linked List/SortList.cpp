// https://leetcode.com/problems/sort-list/
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
    ListNode *merge(ListNode *list1, ListNode *list2) {
        ListNode *dHead = new ListNode(-1);
        ListNode *p = list1, *q = list2, *merged = dHead;
        while (p && q) {
            if (p->val < q->val) {
                merged->next = p;
                p = p->next;
            } else {
                merged->next = q;
                q = q->next;
            }
            merged = merged->next;
        }
        if (p) merged->next = p;
        if (q) merged->next = q;
        ListNode *mergedHead = dHead->next;
        delete dHead;
        return mergedHead;
    }

    ListNode *mergeSort(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head, *tail = nullptr;
        while (fast && fast->next) {
            tail = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        tail->next = nullptr;
        // Two LL -> head...tail , slow...fast
        
        ListNode *l1 = mergeSort(head);
        ListNode *l2 = mergeSort(slow);
        return merge(l1, l2);
    }

  public:
    ListNode *sortList(ListNode *head) {
        return mergeSort(head);
    }
};

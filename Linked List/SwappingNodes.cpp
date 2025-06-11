// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int countNodes(ListNode *head) {
        int count = 0;
        ListNode *temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

  public:
    ListNode *swapNodes(ListNode *head, int k) {
        int size = countNodes(head);
        int k1 = k, k2 = (size - k + 1);
        if (k1 == k2) return head;
        ListNode *temp = head;
        int count = 1;
        ListNode *firstNode = NULL, *secondNode = NULL;
        while (temp != NULL) {
            if (count == k1) {
                firstNode = temp;
            } else if (count == k2) {
                secondNode = temp;
            }
            temp = temp->next;
            count++;
        }
        swap(firstNode->val, secondNode->val);
        return head;
    }
};

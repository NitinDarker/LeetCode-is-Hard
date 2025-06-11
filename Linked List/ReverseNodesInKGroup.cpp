// https://leetcode.com/problems/reverse-nodes-in-k-group/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    ListNode *reverse(ListNode *head, int k) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = head->next;
        int count = 0;
        while (count != k && curr != NULL) {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (curr) next = curr->next;
            count++;
        }
        head->next = curr;
        return prev;
    }

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        int size = countNodes(head);
        int count = 0;
        ListNode *temp = head;
        ListNode *lastHead = NULL;
        ListNode *newHead = NULL;
        ListNode *actualNewHead = NULL;
        while (temp != NULL) {
            if (count == (size / k)) break;
            newHead = reverse(temp, k);
            if (count == 0) actualNewHead = newHead;
            if (lastHead != NULL) {
                lastHead->next = newHead;
            }
            lastHead = temp;
            temp = temp->next;
            count++;
        }
        return actualNewHead;
    }
};

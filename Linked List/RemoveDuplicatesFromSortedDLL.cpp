// [https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1]
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
  public:
    Node *removeDuplicates(struct Node *head) {
        Node *temp = head;
        while (temp->next != nullptr) {
            if (temp->next->data == temp->data) {
                Node *del = temp->next;
                Node *newNext = temp->next->next;
                temp->next = newNext;
                if (newNext) newNext->prev = temp;
                delete del;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};

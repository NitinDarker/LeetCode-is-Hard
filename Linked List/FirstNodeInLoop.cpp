// First Node of the loop in linked list
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
    Node *moveToFirst(Node *slow, Node *fast) {
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

  public:
    Node *findFirstNode(Node *head) {
        Node *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                return moveToFirst(slow, fast);
            }
        }
        return NULL;
    }
};

// https://leetcode.com/problems/copy-list-with-random-pointer/
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
  public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) return head;
        
        Node *cur = head;
        while (cur != nullptr) {
            Node *copy = new Node(cur->val);
            Node *ahead = cur->next;
            cur->next = copy;
            copy->next = ahead;
            cur = copy->next;
        }

        cur = head;
        while (cur != nullptr) {
            Node *copy = cur->next;
            if (cur->random) copy->random = cur->random->next;
            cur = copy->next;
        }

        cur = head;
        Node *dHead = new Node(-1);
        Node *temp = dHead;
        while (cur != nullptr) {
            Node *copy = cur->next;
            cur->next = copy->next;
            temp->next = copy;
            temp = temp->next;
            cur = cur->next;
        }
        Node *copyHead = dHead->next;
        delete dHead;
        return copyHead;
    }
};

// https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Compare {
    bool operator()(Node *a, Node *b) {
        return a->data > b->data;
    }
};

class Solution {
  public:
    Node *mergeKLists(vector<Node *> &arr) {
        int n = arr.size();
        Node *head = new Node(-1);
        Node *temp = head;
        priority_queue<Node *, vector<Node *>, Compare> heap;
        for (int i = 0; i < n; i++) {
            heap.push(arr[i]);
        }
        while (!heap.empty()) {
            Node *cur = heap.top();
            heap.pop();
            if (cur->next != NULL) heap.push(cur->next);
            temp->next = cur;
            temp = temp->next;
        }
        return head->next;
    }
};

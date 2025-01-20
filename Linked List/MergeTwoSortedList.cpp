// Merge two sorted linked lists -> GFG Daily Problem

// Given the head of two sorted linked lists consisting of nodes respectively.
//   The task is to merge both lists and return the head of the sorted merged list.

struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node *sortedHead = new Node(-1); // Dummy Node
        Node *newHead = sortedHead;
        Node *l = head1, *r = head2;
        while (l && r) {
            if (l->data < r->data) {
                sortedHead->next = l;
                sortedHead = sortedHead->next;
                l = l->next;
            } else {
                sortedHead->next = r;
                sortedHead = sortedHead->next;
                r = r->next;
            }
        }
        if (l) sortedHead->next = l;
        if (r) sortedHead->next = r;
        return newHead->next;
    }
};

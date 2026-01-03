#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
    Node *merge(Node *rootA, Node *rootB) {
        Node *dNode = new Node(-1);
        Node *sorted = dNode;
        Node *a = rootA, *b = rootB;
        while (a && b) {
            if (a->data < b->data) {
                sorted->bottom = a;
                a = a->bottom;
            } else {
                sorted->bottom = b;
                b = b->bottom;
            }
            sorted = sorted->bottom;
            sorted->next = NULL;
        }
        if (a)
            sorted->bottom = a;
        if (b)
            sorted->bottom = b;
        return dNode->bottom;
    }

  public:
    Node *flatten(Node *root) {
        if (root == NULL || root->next == NULL) {
            return root;
        }
        Node *nextRoot = flatten(root->next);
        root->next = NULL;
        return merge(root, nextRoot);
    }
};

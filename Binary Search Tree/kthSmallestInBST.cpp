// https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    void inOrder(Node *root, int &val, int &k) {
        if (root == NULL) return;
        inOrder(root->left, val, k);
        if (k == 1) {
            val = root->data;
            k--;
        }
        else k--;
        inOrder(root->right, val, k);
    }

  public:
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        int val = -1;
        inOrder(root, val, k);
        return val;
    }
};

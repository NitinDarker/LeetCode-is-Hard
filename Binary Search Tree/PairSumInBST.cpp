// https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    void inOrder(Node *root, int target, unordered_set<int> &mpp, bool &found) {
        if (root == NULL) return;
        inOrder(root->left, target, mpp, found);
        int needed = target - root->data;
        if (mpp.find(needed) != mpp.end()) found = true;
        mpp.insert(root->data);
        inOrder(root->right, target, mpp, found);

    }

  public:
    bool findTarget(Node *root, int target) {
        unordered_set<int> mpp;
        bool found = false;
        inOrder(root, target, mpp, found);
        return found;
    }
};

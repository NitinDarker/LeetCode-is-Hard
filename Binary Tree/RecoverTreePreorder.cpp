/* 1028. Recover a Tree From Preorder Traversal

We run a preorder depth-first search (DFS) on the root of a binary tree.
At each node in this traversal, we output D dashes (where D is the depth of this node),
then we output the value of this node.
If the depth of a node is D, the depth of its immediate child is D + 1.
The depth of the root node is 0.
If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    TreeNode *recoverFromPreorder(string traversal) {
        int len = traversal.length();
        if (len == 0) {
            return NULL;
        }
        unordered_map<int, TreeNode *> mpp;

        TreeNode *root = new TreeNode(-1); // Dummy root
        root->left = new TreeNode(-1);
        mpp[0] = root;

        int currDepth = 0;
        int currValue = 0;

        for (int i = 0; i < len; i++) {
            if (traversal[i] == '-' && currValue == 0) {
                currDepth++;
            } else if (traversal[i] == '-' && currValue != 0) {
                TreeNode *newNode = new TreeNode(currValue);
                TreeNode *currNode = mpp[currDepth];
                if (currNode->left == NULL) {
                    currNode->left = newNode;
                } else {
                    currNode->right = newNode;
                    mpp.erase(currDepth);
                }
                mpp[currDepth + 1] = newNode;
                currValue = 0;
                currDepth = 1;
            } else {
                currValue = currValue * 10 + (traversal[i] - '0');
            }
        }
        if (currValue) {
            TreeNode *newNode = new TreeNode(currValue);
            TreeNode *currNode = mpp[currDepth];
            if (currNode->left == NULL) {
                currNode->left = newNode;
            } else {
                currNode->right = newNode;
                mpp.erase(currDepth);
            }
        }
        return root->right;
    }
};

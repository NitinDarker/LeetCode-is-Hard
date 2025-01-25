#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Maximum Height/Depth of a Binary Tree ->
// A binary tree's maximum depth is the number of nodes along
// the longest path from the root node down to the farthest leaf node.

class TreeNode {
  public:
    int data;
    TreeNode *left, *right;

    TreeNode(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Using Recursion
int maxHeight(TreeNode *root) {
    if (root == NULL)
        return 0;
    int leftHeight = maxHeight(root->left);
    int rightHeight = maxHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// Using Queue (Level-Order Traversal)
int maxDepth(TreeNode *root) {
    int depth = 0;
    if (root == NULL)
        return depth;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        depth++;
        for (int i = 0; i < size; i++) {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }

    return depth;
}

int main() {

    return 0;
}
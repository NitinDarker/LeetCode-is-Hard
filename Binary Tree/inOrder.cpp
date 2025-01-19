#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class TreeNode {
  public:
    int val;
    TreeNode *left, *right;

    TreeNode(int data) {
        this->val = data;
        left = right = NULL;
    }
};

// Binary Tree -> DFS -> In-Order Traversal -> Recursive
void inOrderRecursive(TreeNode *root, vector<int> &arr) {
    if (root == NULL) {
        return;
    }
    inOrderRecursive(root->left, arr);
    arr.push_back(root->val);
    inOrderRecursive(root->right, arr);
}

// Binary Tree -> DFS -> In-Order Traversal -> Iterative
vector<int> inOrder(TreeNode *root) {
    vector<int> arr;
    if (root == NULL) return arr;
    stack<TreeNode *> st; // Using only 1 stack (same as auxiliary recursive stack)
    TreeNode *node = root;
    while (true) {
        if (node != NULL) {
            st.push(node);
            node = node->left;
        } else {
            if (st.empty()) break;
            node = st.top();
            st.pop();
            arr.push_back(node->val);
            node = node->right;
        }
    }
    return arr;
}

int main() {
    vector<int> ans;
    TreeNode *root = new TreeNode(1);
    // inOrderRecursive(root, ans);
    return 0;
}
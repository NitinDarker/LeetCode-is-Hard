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

// Binary Tree -> DFS -> Pre-Order Traversal -> Recursive
void preOrderRecursive(TreeNode *root, vector<int> &arr) {
    if (root == NULL) {
        return;
    }
    arr.push_back(root->val);
    preOrderRecursive(root->left, arr);
    preOrderRecursive(root->right, arr);
}

// Binary Tree -> DFS -> Pre-Order Traversal -> Iterative
vector<int> perOrder(TreeNode *root) {
    vector<int> arr;
    if (root == NULL) return arr;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();
        st.pop();
        arr.push_back(node->val);
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return arr;
}

int main() {
    vector<int> ans;
    TreeNode *root = new TreeNode(1);
    // preOrderRecursive(root, ans);
    return 0;
}
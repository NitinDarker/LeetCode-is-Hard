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

// Binary Tree -> DFS -> Post-Order Traversal -> Recursive
void postOrderRecursive(TreeNode *root, vector<int> &arr) {
    if (root == NULL) {
        return;
    }
    postOrderRecursive(root->left, arr);
    postOrderRecursive(root->right, arr);
    arr.push_back(root->val);
}

// Binary Tree -> DFS -> Post-Order Traversal -> Iterative
// Using 2 stacks data structures
vector<int> postOrder(TreeNode *root) {
    vector<int> arr;
    if (root == NULL) {
        return arr;
    }
    stack<TreeNode *> st, pt;
    st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();
        pt.push(node);
        st.pop();
        if (node->left)
            st.push(node->left);
        if (node->right)
            st.push(node->right);
    }
    while (!pt.empty()) {
        arr.push_back(pt.top()->val);
        pt.pop();
    }
    return arr;
}

// Using only 1 stack
vector<int> postOrder1Stack(TreeNode *root) {
    vector<int> arr;
    if (root == NULL) return arr;
    stack<TreeNode *> st;
    TreeNode *curr = root;
    TreeNode *lastVisited = nullptr; // Track the last visited node
    while (!st.empty() || curr != NULL) {
        if (curr != NULL) {
            st.push(curr);
            curr = curr->left; // Traverse to the left child
        } else {
            TreeNode *peekNode = st.top(); // Peek at the top of the stack
            // If the right child exists and hasn't been processed
            if (peekNode->right && lastVisited != peekNode->right) {
                curr = peekNode->right; // Move to the right child
            } else {
                arr.push_back(peekNode->val); // Process the node
                lastVisited = peekNode;       // Mark it as visited
                st.pop();                     // Pop from the stack
            }
        }
    }
    return arr;
}

int main() {
    vector<int> ans;
    TreeNode *root = new TreeNode(1);
    // postOrderRecursive(root, ans);
    return 0;
}
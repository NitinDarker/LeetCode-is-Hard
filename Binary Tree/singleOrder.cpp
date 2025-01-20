#include <iostream>
#include <bits/stdc++.h>
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

// All three traversals in one go
vector<vector<int>> allOrder(TreeNode *root) {
    vector<int> preOrder, inOrder, postOrder;
    if (root == NULL) {
        return {preOrder, inOrder, postOrder};
    }
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
    while (!st.empty()) {
        TreeNode *temp = st.top().first;
        int order = st.top().second;
        if (order == 1) {
            preOrder.push_back(temp->val);
            st.top().second++;
            if (temp->left) st.push({temp->left, 1});
        } else if (order == 2) {
            inOrder.push_back(temp->val);
            st.top().second++;
            if (temp->right) st.push({temp->right, 1});
        } else {
            postOrder.push_back(temp->val);
            st.pop();
        }
    }
    return {preOrder, inOrder, postOrder};
}
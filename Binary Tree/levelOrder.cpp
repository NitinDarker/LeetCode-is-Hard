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

// Binary Tree -> BFS -> Level-Order Traversal
vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == NULL) {
        return ans;
    }

    // Using Queue Data Structure
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        vector<int> arr;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            if (q.front()->left != NULL) {
                q.push(q.front()->left);
            }
            if (q.front()->right != NULL) {
                q.push(q.front()->right);
            }
            arr.push_back(q.front()->val);
            q.pop();
        }
        ans.push_back(arr);
    }
    return ans;
}

int main() {
    vector<int> ans;
    TreeNode *root = new TreeNode(1);
    return 0;
}
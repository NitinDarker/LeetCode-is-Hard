// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

#include <bits/stdc++.h>
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
    unordered_set<TreeNode *> findLeaves(TreeNode *root) {
        unordered_set<TreeNode *> leaves;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            unordered_set<TreeNode *> cur;
            while (size--) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                cur.insert(node);
            }
            leaves = cur;
        }
        return leaves;
    }

    TreeNode *lca(TreeNode *root, unordered_set<TreeNode *> &leaves) {
        if (root == NULL || leaves.count(root)) return root;
        TreeNode *leftChild = lca(root->left, leaves);
        TreeNode *rightChild = lca(root->right, leaves);
        if (leftChild && rightChild) return root;
        else if (leftChild) return leftChild;
        else return rightChild;
    }

  public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        unordered_set<TreeNode *> leaves = findLeaves(root);
        return lca(root, leaves);
    }
};

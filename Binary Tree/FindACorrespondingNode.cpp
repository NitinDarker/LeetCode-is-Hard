// 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

// Given two binary trees original and cloned and given a reference to a node target in the original tree.
// The cloned tree is a copy of the original tree.
// Return a reference to the same node in the cloned tree.
// Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode *ans = NULL;
    void getNode(TreeNode *root, int val) {
        if (root == NULL) return;
        if (root->val == val) ans = root;
        getNode(root->left, val);
        getNode(root->right, val);
    }

public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        getNode(cloned, target->val);
        return ans;
    }
};

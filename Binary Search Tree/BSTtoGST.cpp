/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // int greater(TreeNode *root, int sum) {
    //     if (root->right == NULL) return root->val;
    //     int sum = greater(root->right, sum);
    //     return root->val + sum;
    // }
    int sum = 0;

    int Inorder(TreeNode *root) {
        if (root == NULL) return 0;
        Inorder(root->right);
        root->val = root->val + sum;
        sum = root->val;
        Inorder(root->left);
        return root->val;
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        Inorder(root);
        return root;
    }
};

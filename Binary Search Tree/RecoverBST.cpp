// 99. Recover Binary Search Tree
// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake.
// Recover the tree without changing its structure.

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
    void preOrder(vector<TreeNode *> &arr, TreeNode* root) {
        if (root == NULL) return;
        preOrder(arr, root->left);
        arr.push_back(root);
        preOrder(arr, root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> arr;
        preOrder(arr, root);
        int ind1 = -1, ind2 = -1;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i]->val > arr[i+1]->val) {
                if (ind1 == -1) {
                    ind1 = i;
                    ind2 = i+1;
                }
                else {
                    ind2 = i+1;
                    break;
                }
            }
        }
        swap(arr[ind1]->val, arr[ind2]->val);
    }
};

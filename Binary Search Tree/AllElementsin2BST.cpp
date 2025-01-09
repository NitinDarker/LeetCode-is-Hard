// 1305. All Elements in Two Binary Search Trees
// Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

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
    void inOrder(TreeNode *root, vector<int> &arr) {
        if (root == NULL) return;
        inOrder(root->left, arr);
        arr.push_back(root->val);
        inOrder(root->right, arr);
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        inOrder(root1, ans);
        inOrder(root2, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

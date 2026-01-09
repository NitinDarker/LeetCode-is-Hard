// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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

// Recursive
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == NULL || root == p || root == q) return root;
        int rootVal = root->val, pVal = p->val, qVal = q->val;
        if (rootVal < pVal && rootVal < qVal) {
            // LCA is on the right of root
            return lowestCommonAncestor(root->right, p, q);
        }
        if (rootVal > pVal && rootVal > qVal) {
            // LCA is on the left of root
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};

// Iterative
class Solution2 {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        int pVal = p->val, qVal = q->val;
        while (root != NULL) {
            int r = root->val;
            if (r < pVal && r < qVal) root = root->right;
            else if (r > pVal && r > qVal) root = root->left;
            else return root;
        }
        return NULL;
    }
};

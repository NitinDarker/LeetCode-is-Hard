/* 236. Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”
  */

// Time Complexity: O(n)
// Space Complexity: O(n) -> Auxiliary Recursive Stack space
class Solution {
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }
        if (root == p) {
            return p;
        }
        if (root == q) {
            return q;
        }
        TreeNode* leftVal = findLCA(root->left, p, q);
        TreeNode* rightVal = findLCA(root->right, p, q);
        if (leftVal && rightVal) {
            return root;
        } else if (leftVal == NULL) {
            return rightVal;
        } else {
            return leftVal;
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root, p, q);
    }
};


// Using Path to a Node function done previously before
// Time Complexity: O(3n)
// Space Complexity: O(2n) + O(2n)
class Solution2 {
    bool pathToNode(TreeNode *root, vector<TreeNode *> &arr, TreeNode *node) {
        if (root == NULL) {
            return false;
        }
        arr.push_back(root);
        if (root == node) {
            return true;
        }
        if (pathToNode(root->left, arr, node)) {
            return true;
        }
        if (pathToNode(root->right, arr, node)) {
            return true;
        }
        arr.pop_back();
        return false;
    }

  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        vector<TreeNode *> pathP, pathQ;
        pathToNode(root, pathP, p);
        pathToNode(root, pathQ, q);
        int l = 0, r = 0;
        TreeNode *lca = NULL;
        while (l < pathP.size() && r < pathQ.size()) {
            if (pathP[l] == pathQ[r]) {
                lca = pathP[l];
            } else {
                break;
            }
            l++;
            r++;
        }
        return lca;
    }
};

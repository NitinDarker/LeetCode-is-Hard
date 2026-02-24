// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
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
    int dfs(TreeNode *root, int num) {
        if (!root) return 0;
        num = ((num << 1) | root->val);
        if (!root->left && !root->right) return num; // Leaf Node
        return dfs(root->left, num) + dfs(root->right, num);
    }

  public:
    int sumRootToLeaf(TreeNode *root) {
        return dfs(root, 0);
    }
};

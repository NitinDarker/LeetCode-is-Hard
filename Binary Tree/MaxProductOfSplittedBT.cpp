// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
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
    int mod = 1e9 + 7;
    long totalSum = 0;
    long maxP = 0;

    int dfs(TreeNode *root) {
        if (root == NULL) return 0;
        long leftSum = dfs(root->left);
        long rightSum = dfs(root->right);
        long subtreeSum = root->val + leftSum + rightSum;
        maxP = max(maxP, subtreeSum*(totalSum-subtreeSum));
        return subtreeSum;
    }

  public:
    int maxProduct(TreeNode *root) {
        totalSum = dfs(root);
        dfs(root);
        return maxP % mod;
    }
};

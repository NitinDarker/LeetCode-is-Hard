// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
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
  public:
    int maxLevelSum(TreeNode *root) {
        int maxSum = INT_MIN;
        int maxLevel = -1;
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            int curSum = 0;
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                curSum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (curSum > maxSum) {
                maxSum = curSum;
                maxLevel = level;
            }
            level++;
        }
        return maxLevel;
    }
};

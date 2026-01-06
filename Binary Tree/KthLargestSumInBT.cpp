// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
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
    long long kthLargestLevelSum(TreeNode *root, int k) {
        queue<TreeNode *> q;
        vector<long long> levelSum;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            long long curSum = 0;
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                curSum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            levelSum.push_back(curSum);
        }
        int n = levelSum.size();
        if (k > n) return -1;
        sort(levelSum.begin(), levelSum.end());
        return levelSum[n-k];
    }
};

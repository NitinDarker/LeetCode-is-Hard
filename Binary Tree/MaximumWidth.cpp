/* 662. Maximum Width of Binary Tree

Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes),
where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
It is guaranteed that the answer will in the range of a 32-bit signed integer.
*/

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
    int widthOfBinaryTree(TreeNode *root) {
        if (root == NULL) return 0;
        int maxWidth = INT_MIN;
        queue<pair<TreeNode*, long long>> q;
        q.emplace(root, 0);
        while (!q.empty()) {
            int width = (long long)q.back().second - (long long)q.front().second + 1;
            maxWidth = max(maxWidth, width);
            int size = q.size();
            while (size--) {
                TreeNode *node = q.front().first;
                long long ind = q.front().second;
                q.pop();
                if (node->left) q.emplace(node->left, 2*ind);
                if (node->right) q.emplace(node->right, 2*ind + 1);
            }
        }
        return maxWidth;
    }
};

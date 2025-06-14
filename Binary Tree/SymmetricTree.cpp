// https://leetcode.com/problems/symmetric-tree/
// https://www.geeksforgeeks.org/problems/symmetric-tree/1
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    bool checkSymmetric(TreeNode *left, TreeNode *right) {
        if (left == NULL || right == NULL) {
            return left == right;
        }
        if (left->val != right->val) {
            return false;
        }
        bool leftOne = checkSymmetric(left->left, right->right);
        bool rightOne = checkSymmetric(left->right, right->left);
        return leftOne && rightOne;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return checkSymmetric(root->left, root->right);
    }
};


class Solution2 {
    void helper(TreeNode *n1, TreeNode *n2, bool &res) {
        if (n1 == NULL || n2 == NULL) {
            if (n1 != n2) {
                res = false;
            }
            return;
        }
        if (n1->val != n2->val) {
            res = false;
        }
        helper(n1->left, n2->right, res);
        helper(n1->right, n2->left, res);
    }

  public:
    bool isSymmetric(TreeNode *root) {
        bool res = true;
        helper(root, root, res);
        return res;
    }
};

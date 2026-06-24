class Solution {
    bool preOrder(TreeNode *root, int k, unordered_set<int> &ss) {
        if (!root) return false;
        if (ss.count(k - root->val)) return true;
        ss.insert(root->val);
        if (preOrder(root->left, k, ss)) return true;
        if (preOrder(root->right, k, ss)) return true;
        return false;
    }

  public:
    bool findTarget(TreeNode *root, int k) {
        unordered_set<int> ss;
        if (preOrder(root, k, ss)) return true;
        return false;
    }
};

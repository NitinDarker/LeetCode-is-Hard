// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/?envType=daily-question&envId=2025-04-04
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public TreeNode findLCA(TreeNode root, List<TreeNode> leafNodes) {
        if (root == null) return null;
        for (TreeNode leaf : leafNodes) {
            if (leaf == root) return root;
        }
        TreeNode leftVal = findLCA(root.left, leafNodes);
        TreeNode rightVal = findLCA(root.right, leafNodes);
        if (leftVal != null && rightVal != null) return root;
        else if (leftVal == null) return rightVal;
        else return leftVal;
    }
    
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        List<TreeNode> leafNodes = levelOrder(root);
        return findLCA(root, leafNodes);
    }

    private List<TreeNode> levelOrder(TreeNode root) {
        List<TreeNode> res = new ArrayList<>();
        if (root == null) return null;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        while (!q.isEmpty()) {
            List<TreeNode> arr = new ArrayList<>();
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode front = q.remove();
                arr.add(front);
                if (front.left != null) q.add(front.left);
                if (front.right != null) q.add(front.right);
            }
            res = arr;
        }
        return res;
    }
}

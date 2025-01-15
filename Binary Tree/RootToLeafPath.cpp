/* Root to Leaf Paths -> GFG

Given a Binary Tree, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.
Note: The paths should be returned such that paths from the left subtree of any node are listed first, followed by paths from the right subtree.
*/

/* 
Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    vector<vector<int>> allPaths;
    void pathExist(vector<int> &arr, Node* root) {
        if (root == NULL) {
            return;
        }
        arr.push_back(root->data);
        if (root->left == NULL && root->right == NULL) {
            // Leaf Node
            allPaths.push_back(arr);
            arr.pop_back();
            return;
        }
        pathExist(arr, root->left);
        pathExist(arr, root->right);
        arr.pop_back();
        return;
    }

  public:
    vector<vector<int>> Paths(Node *root) {
        vector<int> arr;
        pathExist(arr, root);
        return allPaths;
    }
};

// https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    bool isDeadEnd(Node *root) {

        vector<int> leafNodes;
        set<int> ss;
        queue<Node *> q;

        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                Node *front = q.front();
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
                if (!front->left && !front->right) leafNodes.push_back(front->data);
                ss.insert(front->data);
                q.pop();
            }
        }
        
        for (int node : leafNodes) {
            bool leftSide = (node - 1 <= 0) || (ss.find(node - 1) != ss.end());
            bool rightSide = (ss.find(node + 1) != ss.end());
            if (leftSide && rightSide)
                return true;
        }
        return false;
    }
};

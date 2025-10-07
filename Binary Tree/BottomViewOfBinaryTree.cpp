// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> res;
        queue<pair<Node *, int>> q;
        map<int, int> mpp;
        q.push({root, 0});
        while (!q.empty()) {
            Node *node = q.front().first;
            int level = q.front().second;
            if (node->left) q.push({node->left, level-1});
            if (node->right) q.push({node->right, level+1});
            mpp[level] = node->data;
            q.pop();
        }
        for (auto it : mpp) {
            res.push_back(it.second);
        }
        return res;
    }
};

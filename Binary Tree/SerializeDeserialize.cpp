// https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to serialize a tree into a list.
    vector<int> serialize(Node *root) {
        vector<int> arr;
        if (!root)
            return arr;

        queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            Node *temp = q.front();
            q.pop();

            if (temp) {
                arr.push_back(temp->data);
                q.push(temp->left);
                q.push(temp->right);
            } else {
                arr.push_back(-1); // Using -1 to represent NULL
            }
        }
        return arr;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        if (arr.empty() || arr[0] == -1)
            return NULL;

        Node *root = new Node(arr[0]);
        queue<Node *> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < arr.size()) {
            Node *temp = q.front();
            q.pop();

            // Left child
            if (arr[i] != -1) {
                temp->left = new Node(arr[i]);
                q.push(temp->left);
            }
            i++;

            // Right child
            if (i < arr.size() && arr[i] != -1) {
                temp->right = new Node(arr[i]);
                q.push(temp->right);
            }
            i++;
        }
        return root;
    }
};

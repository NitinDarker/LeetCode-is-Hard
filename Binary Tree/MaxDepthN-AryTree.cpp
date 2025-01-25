// Maximum Depth of a N-ary Tree
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
  public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
  public:
    int maxDepth(Node *root) {
		if (root == NULL) {
			return 0;
		}
		int currentDepth = 0;
		for (Node *child: root->children) {
			currentDepth = max(currentDepth, maxDepth(child));
		}
		return currentDepth + 1;
    }
};

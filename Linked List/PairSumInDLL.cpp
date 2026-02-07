// https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int,int>> res;
        Node *l = head, *r = head;
        while (r->next != nullptr) r = r->next;
        while (l != r && r->next != l) {
            int sum = l->data + r->data;
            if (sum == target) {
                res.push_back({l->data, r->data});
                l = l->next;
                r = r->prev;
            } else if (sum < target) {
                l = l->next;
            } else {
                r = r->prev;
            }
        }
        return res;
    }
};

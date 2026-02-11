// https://leetcode.com/problems/merge-k-sorted-lists/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> heap;
        ListNode *dHead = new ListNode(-1);
        ListNode *merged = dHead;
        for (auto it : lists) {
            if (it) heap.push({it->val, it});
        }
        while (!heap.empty()) {
            auto top = heap.top();
            heap.pop();
            ListNode *node = top.second;
            if (node->next) heap.push({node->next->val, node->next});
            merged->next = node;
            merged = merged->next;
        }
        ListNode *mergedHead = dHead->next;
        delete dHead;
        return mergedHead;
    }
};

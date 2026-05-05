// https://leetcode.com/problems/split-linked-list-in-parts/description/
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
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        int n = 0;
        ListNode *temp = head;
        while (temp) {
            temp = temp->next;
            n++;
        }

        vector<ListNode *> res(k);
        int split = n / k, mod = n % k;
        
        temp = head;
        for (int i = 0; i < k; i++) {
            res[i] = temp;
            for (int j = 1; j < split; j++) {
                if (temp) temp = temp->next;
            }
            if (temp && mod > 0 && split > 0) {
                temp = temp->next;
                mod--;
            }
            if (!temp) continue;
            ListNode *tail = temp;
            temp = temp->next;
            tail->next = nullptr;
        }
        return res;
    }
};

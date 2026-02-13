// https://leetcode.com/problems/design-browser-history/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string val;
    Node *next;
    Node *prev;

    Node(string _val) {
        val = _val;
        next = nullptr;
        prev = nullptr;
    }
};

class BrowserHistory {
    Node *head, *cur;

  public:
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        cur = head;
    }

    void visit(string url) {
        Node *del = cur->next;
        while (del) {
            Node *temp = del->next;
            delete del;
            del = temp;
        }
        cur->next = new Node(url);
        cur->next->prev = cur;
        cur = cur->next;
    }

    string back(int steps) {
        int cnt = 0;
        while (cnt < steps && cur->prev) {
            cur = cur->prev;
            cnt++;
        }
        return cur->val;
    }

    string forward(int steps) {
        int cnt = 0;
        while (cnt < steps && cur->next) {
            cur = cur->next;
            cnt++;
        }
        return cur->val;
    }
};

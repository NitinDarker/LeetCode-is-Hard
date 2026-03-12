// https://leetcode.com/problems/lru-cache/
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    pair<int, int> val;
    Node *prev, *next;
    Node(pair<int, int> val) : val(val), prev(nullptr), next(nullptr) {};
    Node(pair<int, int> val, Node *prev, Node *next) : val(val), prev(prev), next(next) {};
};

class LRUCache {
    int capacity;
    unordered_map<int, Node *> mpp;
    Node *head, *tail;

  public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node({-1, -1});
        tail = new Node({-1, -1});
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1;
        Node *cur = mpp[key];
        Node *a = cur->prev;
        Node *b = cur->next;
        a->next = b;
        b->prev = a;
        cur->next = head->next;
        cur->prev = head;
        head->next->prev = cur;
        head->next = cur;
        return cur->val.second;
    }

    void put(int key, int value) {
        Node *cur = nullptr;
        if (mpp.find(key) == mpp.end()) {
            cur = new Node({key, value});
            mpp[key] = cur;
            if (mpp.size() > capacity) {
                Node *del = tail->prev;
                int key = del->val.first;
                tail->prev = del->prev;
                del->prev->next = del->next;
                mpp.erase(key);
            }
        } else {
            cur = mpp[key];
            Node *a = cur->prev;
            Node *b = cur->next;
            a->next = b;
            b->prev = a;
            cur->val.second = value;
        }
        cur->next = head->next;
        cur->prev = head;
        head->next->prev = cur;
        head->next = cur;
    }
};

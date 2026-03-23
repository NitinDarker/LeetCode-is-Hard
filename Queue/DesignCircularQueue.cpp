// https://leetcode.com/problems/design-circular-queue/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyCircularQueue {
    ListNode *front, *back;
    int cap;

  public:
    MyCircularQueue(int k) {
        cap = k;
        front = nullptr;
        back = nullptr;
    }

    bool enQueue(int value) {
        if (cap == 0)
            return false;
        if (back == nullptr) {
            back = new ListNode(value);
            front = back;
            cap--;
            return true;
        }
        back->next = new ListNode(value);
        back = back->next;
        cap--;
        return true;
    }

    bool deQueue() {
        if (front == nullptr)
            return false;
        cap++;
        ListNode *del = front;
        front = front->next;
        delete del;
        if (front == nullptr)
            back = nullptr;
        return true;
    }

    int Front() {
        if (front == nullptr)
            return -1;
        return front->val;
    }

    int Rear() {
        if (back == nullptr)
            return -1;
        return back->val;
    }

    bool isEmpty() {
        if (front == nullptr)
            return true;
        return false;
    }

    bool isFull() {
        if (cap == 0)
            return true;
        return false;
    }
};

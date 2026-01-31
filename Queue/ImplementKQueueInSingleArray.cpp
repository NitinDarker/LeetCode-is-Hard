#include <bits/stdc++.h>
using namespace std;

class kQueues {
    vector<int> arr, front, back, next;
    int free;

  public:
    kQueues(int n, int k) {
        free = 0;
        arr.assign(n, -1); 
        front.assign(k, -1);
        back.assign(k, -1);
        next.assign(n, -1);
        for (int i = 0; i < n-1; i++) next[i] = i+1;
    }

    // enqueue element x into queue i
    void enqueue(int x, int i) {
        if (isFull()) return ;
        int idx = free;
        free = next[free];
        if (front[i] == -1) front[i] = idx;
        else next[back[i]] = idx;
        back[i] = idx;
        next[idx] = -1;
        arr[idx] = x;
    }

    // dequeue element from queue i
    int dequeue(int i) {
        if (isEmpty(i)) return -1;
        int ele = arr[front[i]];
        int prevFront = front[i];
        front[i] = next[front[i]];
        if (front[i] == -1) back[i] = -1;
        next[prevFront] = free;
        free = prevFront;
        return ele;
    }

    // check if queue i is empty
    bool isEmpty(int i) {
        if (front[i] == -1) return true;
        return false;
    }

    // check if array is full
    bool isFull() {
        if (free == -1) return true;
        return false;
    }
};

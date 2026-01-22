// https://leetcode.com/problems/implement-stack-using-queues/
class MyStack {
public:
    queue<int> q;

    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty())
            return -1;
        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        if (q.empty())
            return -1;
        return q.front();
    }

    bool empty() { return q.empty(); }
};

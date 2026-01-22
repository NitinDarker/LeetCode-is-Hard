// https://leetcode.com/problems/implement-queue-using-stacks/

// Expensive Push - Cheaper Pop
class MyQueue {
public:
    stack<int> s1, s2;
    
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        if (s1.empty()) return -1;
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        if (s1.empty()) return -1;
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};


// Cheaper Push - Expensive Pop
class MyQueue2 {
public:
    stack<int> s1, s2;
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (!s2.empty()) {
            int x = s2.top();
            s2.pop();
            return x;
        }    
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int x = s2.top();
        s2.pop();
        return x;   
    }
    
    int peek() {
        if (!s2.empty()) return s2.top();
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

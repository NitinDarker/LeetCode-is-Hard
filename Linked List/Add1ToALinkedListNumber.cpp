// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/0
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
    Node *reverse(Node *head) {
        Node *prev = nullptr, *cur = head;
        while (cur) {
            Node *ahead = cur->next;
            cur->next = prev;
            prev = cur;
            cur = ahead;
        } 
        return prev;
    }

  public:
    Node *addOne(Node *head) {
        Node *rev = reverse(head);
        bool carry = 1;
        Node *tmp = rev;
        while (tmp->next) {
            if (tmp->data == 9) {
                tmp->data = 0;
            } else {
                tmp->data = tmp->data + carry;
                carry = 0;
                break;
            } 
            tmp = tmp->next;
        }
        if (carry && tmp->data == 9) {
            tmp->data = 0;
            tmp->next = new Node(1);
        } else if (carry) {
            tmp->data = tmp->data + 1;
        }
        return reverse(rev);
    }
};

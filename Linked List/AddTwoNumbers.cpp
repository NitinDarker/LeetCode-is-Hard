// Add Number Linked Lists -> GFG Daily Problem (Medium)

// Given the head of two singly linked lists num1 and num2 representing two non-negative integers. 
// The task is to return the head of the linked list representing the sum of these two numbers.
// For example, num1 represented by the linked list : 1 -> 9 -> 0, similarly num2 represented by the linked list: 2 -> 5.
// Sum of these two numbers is represented by 2 -> 1 -> 5.
// Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
    Node *reverseList(Node *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        Node *left = NULL;
        Node *middle = head;
        while (middle) {
            Node *right = middle->next;
            middle->next = left;
            left = middle;
            middle = right;
        }
        return left;
    }

  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        Node *reversed1 = reverseList(num1);
        Node *reversed2 = reverseList(num2);
        Node *l = reversed1, *r = reversed2;
        Node *sumHead = new Node(-1); // DUMMY head
        Node *temp = sumHead;
        int carry = 0;
        while (l || r) {
            int a, b;
            if (l) a = l->data;
            else a = 0;
            if (r) b = r->data;
            else b = 0;
            int sum = a + b + carry;
            if (sum > 9) {
                sum %= 10;
                carry = 1;
                temp->next = new Node(sum);
                
            } else {
                temp->next = new Node(sum);
                carry = 0;
            }
            temp = temp->next;
            if (l) l = l->next;
            if (r) r = r->next;
        }
        if (carry == 1) {
            temp->next = new Node(carry);
        }
        Node *ansHead = reverseList(sumHead->next);
        while (ansHead->data == 0) {
            ansHead = ansHead->next;
        }
        return ansHead;
    }
};

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
    void circularLink(Node *head) {
        Node *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = head;
    }

    int findSize(Node *head) {
        int size = 0;
        Node *temp = head;
        while (temp) {
            size++;
            temp = temp->next;
        }
        return size;
    }

    Node *findKthNode(Node *head, int k) {
        Node *temp = head;
        int counter = 0;
        while (temp) {
            counter++;
            if (counter == k) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

  public:
    Node* rotate(Node* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        int size = findSize(head);
        k = k % size;
        if (k == 0) return head;
        circularLink(head);
        Node *kthNode = findKthNode(head, k);
        Node* newHead = kthNode->next;
        kthNode->next = NULL;
        return newHead;
    }
};

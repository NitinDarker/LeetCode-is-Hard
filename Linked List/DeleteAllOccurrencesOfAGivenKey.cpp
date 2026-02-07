// https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

class Solution {
  public:
    void deleteAllOccurOfX(struct Node **head, int x) {
        Node *dNode = new Node;
        dNode->data = -1;
        dNode->next = *head;
        dNode->prev = nullptr;
        Node *temp = dNode;
        while (temp->next != nullptr) {
            if (temp->next->data == x) {
                Node *del = temp->next;
                Node *newNext = temp->next->next;
                temp->next = newNext;
                if (newNext) newNext->prev = temp;
                delete del;
                continue;
            }
            temp = temp->next;
        }
        if (*head) *head = (dNode->next);
        (*head)->prev = nullptr;
        delete dNode;
    }
};

class Solution {
    ListNode* findMiddle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* leftList, ListNode* rightList) {
        // Merge while sorting
        ListNode* l = leftList;
        ListNode* r = rightList;
        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;
        while (l && r) {
            if (l->val < r->val) {
                temp->next = l;
                l = l->next;
            } else {
                temp->next = r;
                r = r->next;
            }
            temp = temp->next;
        }
        if (!l) {
            temp->next = r;
        }
        if (!r) {
            temp->next = l;
        }
        return dNode->next;
    }

    ListNode* mergeSort(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        ListNode* middleNode = findMiddle(head);
        ListNode *leftList = head, *rightList = middleNode->next;
        middleNode->next = NULL;
        leftList = mergeSort(leftList);
        rightList = mergeSort(rightList);
        head = merge(leftList, rightList);
        return head;
    }

public:
    ListNode* sortList(ListNode* head) { return mergeSort(head); }
};

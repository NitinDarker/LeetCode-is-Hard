/* 86. Partition List

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return head;
        ListNode* smallList = new ListNode(-1);
        ListNode* bigList = new ListNode(-1);
        ListNode* smallHead = smallList;
        ListNode* bigHead = bigList;
        ListNode* temp = head;
        while (temp != NULL) {
            if (temp->val < x) {
                smallList->next = temp;
                smallList = smallList->next;
            } else if (temp->val > x) {
                bigList->next = temp;
                bigList = bigList->next;
            } else {
                break;
            }
            temp = temp->next;
        }
        if (!temp) {
            smallList->next = bigHead->next;
            bigList->next = NULL;
            return smallHead->next;
        }
        bigList->next = temp;
        bigList = bigList->next;
        temp = temp->next;
        ListNode* rightList = new ListNode(-1);
        ListNode* rightHead = rightList;
        while (temp) {
            if (temp->val < x) {
                smallList->next = temp;
                smallList = smallList->next;
            } else {
                rightList->next = temp;
                rightList = rightList->next;
            }
            temp = temp->next;
        }
        smallList->next = bigHead->next;
        bigList->next = rightHead->next;
        rightList->next = NULL;
        return smallHead->next;
    }
};

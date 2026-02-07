// https://leetcode.com/problems/remove-linked-list-elements/?utm_source=chatgpt.com
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dNode = new ListNode(-1, head);
        ListNode *temp = dNode;
        while (temp->next != nullptr) {
            if (temp->next->val == val) {
                ListNode *del = temp->next;
                temp->next = temp->next->next;
                delete del;
                continue;
            }
            temp = temp->next;
        }
        ListNode *newHead = dNode->next;
        delete dNode;
        return newHead;
    }
};

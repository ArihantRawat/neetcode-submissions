class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) return head;
            temp = temp->next;
        }

        ListNode* t = NULL;
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* x = curr->next;
            curr->next = t;
            t = curr;
            curr = x;
        }
        head->next = reverseKGroup(curr, k);

        return t;
    }
};
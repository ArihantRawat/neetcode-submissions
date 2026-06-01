/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;
        int x = 0;
        while(l1 || l2 || x) {
            if(l1) {
                x+=l1->val;
                l1=l1->next;
            }
            if(l2) {
                x+=l2->val;
                l2=l2->next;
            }
            ListNode* t = new ListNode(x%10);
            dummy->next=t;
            dummy=t;
            x=x/10;
        }
        return res->next;;
    }
};

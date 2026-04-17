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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(true) {
            int c = 0;
            ListNode* data = new ListNode(1001);
            int x = 0;
            for(int i =0 ;i<lists.size();i++) {
                if(!lists[i]) {
                    c++;
                } else {
                    if (lists[i]->val<data->val) {
                        x=i;
                        data = lists[i];
                    }
                }
            }
            if(c==lists.size()){
                break;
            }
            lists[x] = lists[x]->next;
            curr->next=data;
            curr = curr->next;
        }

        return dummy -> next;
    }
};

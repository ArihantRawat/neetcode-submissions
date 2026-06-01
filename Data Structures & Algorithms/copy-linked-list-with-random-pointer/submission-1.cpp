class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (!head) return NULL;

        vector<Node*> lt;
        unordered_map<Node*, Node*> mp;

        Node* x = head;

        while (x) {
            Node* t = new Node(x->val);
            mp[x] = t;
            lt.push_back(t);
            x = x->next;
        }

        x = head;

        int i = 0;

        while (x) {

            lt[i]->next = x->next ? mp[x->next] : NULL;
            lt[i]->random = x->random ? mp[x->random] : NULL;

            x = x->next;
            i++;
        }

        return lt[0];
    }
};
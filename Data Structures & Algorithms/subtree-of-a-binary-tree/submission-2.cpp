/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        bool res = false;
        q.push(root);
        while(!q.empty()) {
            TreeNode* x = q.front();
            q.pop();
            if(x->left) {
                q.push(x->left);
            } 
            if(x->right) {
                q.push(x->right);
            }
            if(x->val == subRoot->val) {
                res = res || isSameTree(x,subRoot);
            }
        }
        return res;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p&&!q) || (!p&&q)) {
            return false;
        } else if(!p && !q){
            return true;
        }
        
        return p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

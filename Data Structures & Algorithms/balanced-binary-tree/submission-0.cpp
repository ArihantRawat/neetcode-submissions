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
    bool isBalanced(TreeNode* root) {
        bool res = true;
        getResult(res, root);
        return res;
    }

    int getResult(bool& res, TreeNode* root) {
        if(!root) {
            return 0;
        }
        int l = getResult(res, root->left);
        int r = getResult(res, root->right);
        res = res && abs(l-r)<=1;
        return max(l,r)+1;
    }
};

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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        getResult(res, root);
        return res;
    }

    int getResult(int& res, TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = getResult(res, root->left);
        int r = getResult(res, root->right);
        res = max(res,l+r);
        return 1 + max(l,r);
    }
};

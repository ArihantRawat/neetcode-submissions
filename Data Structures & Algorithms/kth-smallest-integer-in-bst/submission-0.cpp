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
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        getData(root,k,res);
        return res;
    }

    void getData(TreeNode* root, int& k, int& res) {
        if (!root || k<1) {
            return;
        }
        getData(root->left,k,res);
        k--;
        if(k==0) {
            res=root->val;
        }
        getData(root->right,k,res);
    }
};

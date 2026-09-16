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
    bool fn(TreeNode* curr, long long minval, long long maxval){
        if(!curr) return true;
        
        if(curr->val <= minval || curr->val >= maxval) return false;

        return fn(curr->left, minval, curr->val) && fn(curr->right, curr->val, maxval);
    }
    
    bool isValidBST(TreeNode* root) {
        return fn(root, LLONG_MIN, LLONG_MAX);
    }
};
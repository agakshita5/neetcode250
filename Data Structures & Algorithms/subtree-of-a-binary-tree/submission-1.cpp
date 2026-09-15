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
    bool isIdentical(TreeNode* c1, TreeNode* c2){
        if(!c1 && !c2) return true;
        if(!c1 || !c2) return false;
        if(c1->val != c2->val) return false;
        
        return isIdentical(c1->left, c2->left) && isIdentical(c1->right, c2->right);
    }
    int dfs(TreeNode* curr, TreeNode* subroot){
        if(!curr) return false;

        if(curr->val == subroot->val){ // node matched with subroot
            bool res = isIdentical(curr, subroot); // check if identical subtrees
            if(res) return res;
        }
        return dfs(curr->left, subroot) || dfs(curr->right, subroot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        return dfs(root, subroot);
    }
};

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
    int res = 0;

    int dfs(TreeNode* curr){
        if(!curr) return 0;

        int L = dfs(curr->left);
        int R = dfs(curr->right);

        res = max(res, L+R); // keep max diam found so far

        return max(L,R) + 1; // return ht of a subtree from curr's parent as a root
        // 1 is ht from 3->5
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};

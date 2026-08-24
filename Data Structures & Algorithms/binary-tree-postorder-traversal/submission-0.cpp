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
    vector<int> v;
    public:
        void postorder(TreeNode* n){
            if(!n) return;
            postorder(n->left);
            postorder(n->right);
            v.push_back(n->val);
        }
        vector<int> postorderTraversal(TreeNode* root) {
            postorder(root);
            return v;
        }
};
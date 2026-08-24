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

// root left right
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st; // 3X 4X
        vector<int> v; 
        TreeNode* curr = root;

        while(curr || !st.empty()){
            if(curr){
                // root
                v.push_back(curr->val); // 1 2 4 3 5
                // stack is LIFO 
                // (last in should be right node so that left proccessed next)
                st.push(curr->right); // 3 4 
                curr = curr->left; // 2 null null 5 null
            }else{
                // left = null
                // continue with right subtree when left is null
                curr = st.top(); // 4 3 nothing
                st.pop();
            }
        }
        return v; // 1 2 4 3 5
    }
};


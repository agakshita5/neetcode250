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


// using stack = O(1)
// left root right

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> v;
        TreeNode* curr = root;

        while(curr || !st.empty()){
            // go left as much as possible
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            // now curr is left -> start popping from stack
            curr = st.top();
            st.pop();

            // add curr val to v -> left
            v.push_back(curr->val);
            curr = curr->right;
        }
        return v;
    }
};
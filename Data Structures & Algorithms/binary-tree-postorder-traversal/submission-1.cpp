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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st; 
        stack<bool> visited;

        st.push(root); visited.push(false);

        vector<int> v; 

        while(!st.empty()){
            TreeNode* curr = st.top();
            bool isVs = visited.top();
            st.pop(); visited.pop();

            if(curr){
                if(isVs){
                    v.push_back(curr->val);
                }else{ // when curr node is not visited
                    st.push(curr);
                    visited.push(true);
                    st.push(curr->right);
                    visited.push(false);
                    st.push(curr->left);
                    visited.push(false);
                }
            }
        }
        return v;
    }
};
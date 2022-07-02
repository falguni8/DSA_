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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *x=root;
        while(x){
            if(x->val>val){
                if(x->left==NULL){
                    x->left=new TreeNode(val);
                    return root;
                }
                else{
                    x=x->left;
                }
            }
            else{
                if(x->right==NULL){
                    x->right=new TreeNode(val);
                    return root;
                }
                else{
                    x=x->right;
                }
            }
        }
        if(root==NULL){
            return new TreeNode(val);
        }
        return NULL;
    }
};
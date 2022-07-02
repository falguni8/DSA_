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
    bool ans(TreeNode* x,long long int low,long long int  high){
        if(x==NULL){
            return true;
        }
        if(x->val>=high || x->val<=low){
             return false;
        }
       
        return ans(x->left,low,x->val) && ans(x->right,x->val,high);
    }
    bool isValidBST(TreeNode* root) {
        return ans(root,LLONG_MIN,LLONG_MAX);
    }
};
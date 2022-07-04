/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool fun(TreeNode *x,int B,int sum){
    if(x==NULL){
        return 0;
    }
    if(x->left==NULL && x->right==NULL && sum+x->val==B){
        return 1;
    }
    return fun(x->left,B,sum+x->val) || fun(x->right,B,sum+x->val);
 }
int Solution::hasPathSum(TreeNode* A, int B) {
    return fun(A,B,0);
}

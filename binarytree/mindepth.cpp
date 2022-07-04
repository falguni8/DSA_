/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void height(TreeNode *x,int curr,int &ans){
    if(x==NULL){
        return ;
    }
    if(x && x->left==NULL && x->right==NULL){
        //cout<<x->val<<" ";
        ans=min(curr+1,ans);
        ///cout<<curr+1<<" "<<ans<<" ";
    }
    if(x->left){
        height(x->left,curr+1,ans);
    }
    if(x->right){
        height(x->right,curr+1,ans);
    }
}
int Solution::minDepth(TreeNode* A) {
    int ans=INT_MAX;
    height(A,0,ans);
    return ans;
}

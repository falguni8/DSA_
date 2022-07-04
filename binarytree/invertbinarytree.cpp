/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void fun(TreeNode *root){
     if(root==NULL){
         return ;
     }
     TreeNode*temp=root->left;
     root->left=root->right;
     fun(root->left);
     root->right=temp;
     fun(root->right);
 }
TreeNode* Solution::invertTree(TreeNode* A) {
    TreeNode *x=A;
    fun(x);
    return A;
}

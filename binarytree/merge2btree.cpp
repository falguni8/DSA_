/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* Function to merge given two binary trees*/
TreeNode *MergeTrees(TreeNode * t1, TreeNode * t2) 
{ 
    if (!t1) 
        return t2; 
    if (!t2) 
        return t1; 
    t1->val += t2->val; 
    t1->left = MergeTrees(t1->left, t2->left); 
    t1->right = MergeTrees(t1->right, t2->right); 
    return t1; 
} 
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    return MergeTrees(A,B);
}

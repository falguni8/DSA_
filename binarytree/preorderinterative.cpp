/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int>v;
    stack<TreeNode*>s;
    //root left right
     s.push(A);
    while(!s.empty()){
        v.push_back(s.top()->val);
        TreeNode *x=s.top();
        s.pop();
        if(x->right){
            s.push(x->right);
        }
        if(x->left){
            s.push(x->left);
        }
    }
    return v;
}

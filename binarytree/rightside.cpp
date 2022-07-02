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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        fun(root,0,v);
        return v;
    }
private:
    void fun(TreeNode* x,int level,vector<int>&v){
        if(x==NULL){
            return ;
        }
        if(v.size()==level){
            v.push_back(x->val);
        }
        fun(x->right,level+1,v);
        fun(x->left,level+1,v);
    }
};
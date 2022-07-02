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
    int maxPathSum(TreeNode* root) {
        int d=INT_MIN;
        height(root,d);
        return d;
    }
private:
    int height(TreeNode* root,int& d){
        if(root==NULL){
            return 0;
        }
        int lh=max(0,height(root->left,d));
        int rh=max(0,height(root->right,d));
        d=max(d,lh+rh+root->val);
        return max(lh,rh)+root->val;
    }
};
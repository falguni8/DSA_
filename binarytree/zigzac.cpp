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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>levelorder;
        if(root==NULL){
            return levelorder;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>l;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* t=q.front();
                q.pop();
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                l.push_back(t->val);
            }
            levelorder.push_back(l);
        }
        for(int i=1;i<levelorder.size();i+=2){
            vector<int>k=levelorder[i];
            reverse(k.begin(),k.end());
            levelorder[i]=k;
        }
        return levelorder;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////


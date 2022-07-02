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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> node;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            TreeNode* n=a.first;
            int x=a.second.first;
            int y=a.second.second;
            node[x][y].insert(n->val);
            if(n->left!=NULL){
                q.push({n->left,{x-1,y+1}});
            }
            if(n->right!=NULL){
                q.push({n->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p:node){
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
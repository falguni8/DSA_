class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return root;
        }
        while(root!=NULL){
               if(p->val<root->val && q->val<root->val){
                   root=root->left;
               }
               else if(p->val>root->val && q->val>root->val){
                   root=root->right;
               }
               else{
                    return root;
               }
        }
        return NULL;
    }
};
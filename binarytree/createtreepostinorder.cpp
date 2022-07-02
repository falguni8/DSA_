class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())
            return NULL;
        map<int,int> hm;
        for(int i=0;i<inorder.size();i++)
            hm[inorder[i]]=i;
        TreeNode* root=solve(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,hm);
        return root;
    }
    TreeNode* solve(vector<int> &inorder,int is,int ie,vector<int> &postorder,int ps,int pe,map<int,int> &hm){
        if(ps>pe || is>ie)
            return NULL;
        TreeNode* root=new TreeNode(postorder[pe]);
        int inRoot=hm[postorder[pe]];
        int numsleft=inRoot-is;
        root->left=solve(inorder,is,inRoot-1,postorder,ps,ps+numsleft-1,hm);
        root->right=solve(inorder,inRoot+1,ie,postorder,ps+numsleft,pe-1,hm);
        return root;
    }
};
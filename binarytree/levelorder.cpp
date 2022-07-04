//reverse
vector<int> Solution::solve(TreeNode* A) {
    vector<int>l;
    queue<TreeNode*>q;
    q.push(A);
    while(!q.empty()){
        TreeNode *x=q.front();
        q.pop();
        l.push_back(x->val);
        if(x->right){
            q.push(x->right);
        }
        if(x->left){
            q.push(x->left);
        }
    }
    reverse(l.begin(),l.end());
    return l;
}

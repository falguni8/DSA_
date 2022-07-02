bool fun(TreeNode *A,int B,vector<int>&v){
    if(A==NULL){
        return false;
    }
    v.push_back(A->val);
    if(A->val==B){
        return true;
    }
    if(fun(A->left,B,v) || fun(A->right,B,v)){
        return true;
    }
    v.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>v;
    if(A==NULL){
        return v;
    }
    fun(A,B,v);
    return v;
}

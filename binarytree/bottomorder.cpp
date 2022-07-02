class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*,int>>q;
        map<int,int>m;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            Node *x=it.first;
            int level=it.second;
            if(x->left){
                q.push({x->left,level-1});
            }
            if(x->right){
                q.push({x->right,level+1});
            }
            m[level]=x->data;
            q.pop();
        }
        vector<int>ans;
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};
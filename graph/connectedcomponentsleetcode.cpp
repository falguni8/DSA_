class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)
            return -1;
        vector<bool>vis(n,false);
        vector<vector<int>> adj(n);
        for(auto v : connections){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans-1;
    }
    void dfs(int k,vector<vector<int>>&adj,vector<bool>&vis){
        vis[k]=true;
        for(auto i :adj[k]){
            if(vis[i]==0){
                dfs(i,adj,vis);
            }
        }
    }
};
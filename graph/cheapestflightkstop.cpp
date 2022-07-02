class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int>stop(n,INT_MAX);
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>>q;
        q.push({{0,src},0});
        while(!q.empty()){
            int d=q.top().first.first;
            int x=q.top().first.second;
            int step=q.top().second;
            q.pop();
            if(step>stop[x] || step>k+1)
                continue;
            stop[x]=step;
            if(x==dst){
                return d;
            }
            for(auto i:adj[x]){
                int wt=i.second;
                int y=i.first;
                q.push({{d+wt,y},step+1});
            }
        }
        return -1;
    }
};
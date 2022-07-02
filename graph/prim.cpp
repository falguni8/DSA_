// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mst;
        vector<int>par(V,-1);
        vector<int>key(V,INT_MAX);
        vector<int>mstvis(V,0);
        mst.push({0,0});
        key[0]=0;
        par[0]=-1;
        while(!mst.empty()){
            int d=mst.top().first;
            int x=mst.top().second;
            mst.pop();
            mstvis[x]=1;
            for(auto j:adj[x]){
                
                if(mstvis[j[0]]==0 && key[j[0]]>j[1]){
                    key[j[0]]=j[1];
                    par[j[0]]=x;
                    mst.push({key[j[0]],j[0]});
                }
            }
        }
        int sum=0;
        for(int i=0;i<V;i++){
            sum+=key[i];
        }
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
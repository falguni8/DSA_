// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	int c=0;
	void dfs(int x,vector<int>&vis,stack<int>&stk,vector<int> adj[]){
            vis[x]=1;
            for(auto y:adj[x]){
                if(!vis[y]){
                    dfs(y,vis,stk,adj);
                }
            }
            stk.push(x);
    }
    void revdfs(int x,vector<int>&vis,vector<int> transpose[]){
            vis[x]=1;
            for(auto y:transpose[x]){
                if(!vis[y]){
                    revdfs(y,vis,transpose);
                }
            }
    }
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int>vis(V+1,0);
	    stack<int>stk;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,stk,adj);
            }
        }
        vector<int>transpose[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto j :adj[i]){
                transpose[j].push_back(i);
            }
        }
        int c=0;
        while(!stk.empty()){
            int x=stk.top();
            stk.pop();
            if(!vis[x]){
                revdfs(x,vis,transpose);
                c++;
            }
        }
        return c;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
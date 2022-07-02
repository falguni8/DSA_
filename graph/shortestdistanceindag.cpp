/*
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	vector<int> dis(int V, vector<int> adj[]) 
	{
	    vector<int>dis(V,INT_MAX);
        vector<int>ans;
	    vector<int>indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto x:adj[i]){
	            indegree[x]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int x=q.front();
	        q.pop();
            ans.push_back(x);
	        for(auto y:adj[x]){
	            indegree[y]--;
	            if(indegree[y]==0){
	                q.push(y);
	            }
	        }
	    }
        dis[0]=0;
	    for(int i=0;i<ans.size();i++){
            for(auto j:adj[i]){
                dis[j]=min(dis[i]+adj[i][j],dis[j]);
            }
        }
        for(int i=0;i<V;i++){
            cout<<dis[i]<<" ";
        }
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
/*
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
*/


#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 

void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int,int>> adj[]) {
    vis[node] = 1; 
    for(auto it : adj[node]) {
        if(!vis[it.first]) {
            findTopoSort(it.first, vis, st, adj); 
        }
    }
    st.push(node);
}


void shortestPath(int src, int N, vector<pair<int,int>> adj[]) 
{ 
	int vis[N] = {0};
	stack<int> st; 
	for (int i = 0; i < N; i++) 
		if (!vis[i]) 
			findTopoSort(i, vis, st, adj); 
			
	int dist[N]; 
	for (int i = 0; i < N; i++) 
		dist[i] = 1e9; 
	dist[src] = 0; 

	while(!st.empty()) 
	{  
		int node = st.top(); 
		st.pop(); 
 
		if (dist[node] != INF) {
		    for(auto it : adj[node]) {
		        if(dist[node] + it.second < dist[it.first]) {
		            dist[it.first] = dist[node] + it.second; 
		        }
		    }
		}
	} 

	for (int i = 0; i < N; i++) 
		(dist[i] == 1e9)? cout << "INF ": cout << dist[i] << " "; 
} 

int main() 
{ 
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    adj[u].push_back({v, wt}); 
	}
	
	shortestPath(0, n, adj); 

	return 0; 
} 
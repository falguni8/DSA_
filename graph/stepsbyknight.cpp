// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
	    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	    queue<pair<pair<int,int>,int>>q;
	    q.push({{KnightPos[0],KnightPos[1]},0});
	    int ans=0;
	    bool vis[N+1][N+1];
	    for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                vis[i][j] = false;
        vis[KnightPos[0]][KnightPos[1]]=true;
	    while(!q.empty()){
	        int x=q.front().first.first;
	        int y=q.front().first.second;
	        int d=q.front().second;
	        if(x==TargetPos[0] && y==TargetPos[1]){
	            return d;
	        }
	        q.pop();
	        for(int i=0;i<8;i++){
	            if(isvalid(x+dx[i],y+dy[i],N) && vis[x+dx[i]][y+dy[i]]==false){
	                q.push({{x+dx[i],y+dy[i]},d+1});
	                vis[x+dx[i]][y+dy[i]]=true;
	            }
	        }
	    }
	}
	private:
	bool isvalid(int x, int y, int N){
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
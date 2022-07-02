// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int solve(int e,int f){
        if(f==0 || f==1){
            dp[e][f]=f;
        }
        if(e==1){
            dp[e][f]=f;
        }
        if(dp[e][f]!=-1){
            return dp[e][f];
        }
        int ans=INT_MAX;
        for(int k=1;k<f;k++){
            if(dp[e-1][k-1]==-1){
                dp[e-1][k-1]=solve(e-1,k-1);
            }
            if(dp[e][f-k]==-1){
                dp[e][f-k]=solve(e,f-k);
            }
            ans=min(ans,1+max(dp[e-1][k-1],dp[e][f-k]));
        }
        return dp[e][f]=ans;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
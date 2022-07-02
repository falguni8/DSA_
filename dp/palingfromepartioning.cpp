// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int dp[10001][10001];
class Solution{
public:
    bool ispalingdrome(string X,int i,int j){
        while (i <= j) {
    		if (X[i] != X[j])
    			return false;
    		i++, j--;
	    }
	    return true;
    }
    int solve(string str,int i,int j){
        if (i>=j || ispalingdrome(str,i,j)){
            dp[i][j]=0;
        }
        int ans=INT_MAX;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(int k=i;k<j;k++){
            int tempans;
            if(dp[i][k]!=-1){
                tempans=dp[i][k]+dp[k+1][j]+1;
            }
            else{
                dp[i][k]=solve(str,i,k);
                dp[k+1][j]=solve(str,k+1,j);
                tempans=dp[i][k]+dp[k+1][j]+1;
            }
            ans=min(ans,tempans);
            dp[i][j]=ans;
        }
        return dp[i][j];
    }
    int palindromicPartition(string str)
    {
        // code her
        //return j;
        memset(dp,-1,sizeof(dp));
        return solve(str,0,str.length()-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
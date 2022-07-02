#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    int dp[n+1][sum+1];
	    for(int i=0;i<n+1;i++){
	        for(int j=0;j<sum+1;j++){
	            if(j==0){
	                dp[i][j]=1;
	            }
	            else if(i==0){
	                dp[i][j]=0;
	            }
	        }
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=0;j<=sum;j++){
	            if(j>=arr[i-1]){
	                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
	            }
	            else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    int ans=1000001;
	    for(int i=1;i<=n;i++){
	        for(int j=sum/2;j<=sum;j++){
	            if(dp[i][j] && dp[i][sum-j]){
                    //x=j y=sum-j
                    //y-x=sum-j-j=sum-2*j
	                ans=min(abs(sum-2*j),ans);
	            }
	        }
	    }
	    return(ans);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
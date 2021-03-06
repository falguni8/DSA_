// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int isSubsetSum(vector<int>arr,int d){
        // code here 
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        sum=(sum+d)/2;
        int dp[n+1][sum+1];
        for(int i =0;i<n+1;i++){
           for(int j =0;j<sum+1;j++){
               if(i==0){
                   dp[i][j] =0;
               }
               if(j==0){
                   dp[i][j] = 1;
               }
           }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, d;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> d;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, d) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
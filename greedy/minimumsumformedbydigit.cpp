// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        sort(arr,arr+n);
        long long int digit1=0;
        long long int digit2=0;
        for(int i=0;i<n;i+=2){
            digit1=digit1*10;
            digit1+=arr[i];
        }
        for(int i=1;i<n;i+=2){
            digit2=digit2*10;
            digit2+=arr[i];
        }
        return digit1+digit2;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
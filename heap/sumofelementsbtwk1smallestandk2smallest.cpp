// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        long long a=kthSmallest(A,0,N,K1);
        long long b=kthSmallest(A,0,N,K2);
        long long sum=0;
        for(long long i=0;i<N;i++){
            if(A[i]>a && A[i]<b){
                sum+=A[i];
            }
        }
        return sum;
    }
private:
    long long kthSmallest(long long arr[], long long l, long long r,long long k) {
        //code here
        priority_queue<long long> h;
        for(long long i=l;i<=r;i++){
            h.push(arr[i]);
            while(h.size()>k){
                h.pop();
            }
        }
        return h.top();
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends
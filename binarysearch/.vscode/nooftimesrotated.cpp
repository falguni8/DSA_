// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int ind=binarysearch(arr,n);
	    return ind;
	}
	
private:
int binarysearch(int arr[],int n){
    int low=0;
    int high=n-1;
    if(arr[low]<arr[high]){
            return 0;
    }
    while(low<=high){
        int mid=low+(high-low)/2;
        int prev=arr[(mid+n-1)%n];
        int next=arr[(mid+1)%n];
        //cout<<arr[mid]<<" "<<prev<<" "<<next<<"\n";
        if(arr[mid]<=prev && arr[mid]<=next){
            //cout<<mid<<" ";
            return mid;
        }
        if(arr[mid]>=arr[high]){
            low=mid+1;
        }
        if(arr[high]>=arr[mid]){
            high=mid-1;
        }
    }
}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
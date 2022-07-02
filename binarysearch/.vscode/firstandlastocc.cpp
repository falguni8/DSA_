// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        int a=firstocc(arr,x,n);
        int b=lastocc(arr,x,n);
        vector<int>v;
        v.push_back(a);
        v.push_back(b);
        if(a==-1 && b==-1){
            return {-1};
        }
        return v;
    }
    
    private:
        int firstocc(vector<int>&arr,int key,int n){
            int start=0;
            int end=n-1;
            while(start<=end){
                int mid=start+(end-start)/2;
                if(arr[mid]==key){
                    while(arr[mid-1]==key && mid-1>=0){
                        mid--;
                    }
                    return mid++;
                }
                if(arr[mid]>key){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            return -1;
        }
        int lastocc(vector<int>&arr,int key,int n){
            int start=0;
            int end=n-1;
            while(start<=end){
                int mid=start+(end-start)/2;
                if(arr[mid]==key){
                    while(arr[mid+1]==key && mid+1<=end){
                        mid++;
                    }
                    return mid;
                }
                if(arr[mid]>key){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            return -1;
        }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}
  // } Driver Code Ends
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int kadane(int nums[],int n){
            
        int sum=INT_MIN;
        int curr_sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                curr_sum+=nums[i];
            }
            else if(curr_sum+nums[i]>0){
                curr_sum+=nums[i];
            }
            else{
                curr_sum=0;
            }
            sum=max(sum,curr_sum);
        }
        if(sum==0){
            sort(nums,nums+n);
            sum=nums[n-1];
        }
        return sum;
    }
    
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int s=kadane(arr,num);
        int sum=0;
        for(int i=0;i<num;i++){
            sum+=arr[i];
            arr[i]=-arr[i];
        }
        int p=kadane(arr,num);
        //cout<<s<<" "<<sum+p;
        
        if(max(s,sum+p)!=0){
            return max(s,sum+p);
        }
        else{
            return min(s,sum+p);
        }
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
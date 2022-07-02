#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int>v;
       stack<int>s;
       for(int i=0;i<n;i++){
           while(!s.empty() && price[i]>=price[s.top()]){
               s.pop();
           }
           if(s.empty()){
               v.push_back(-1);
           }
           else{
               v.push_back(s.top());
           }
           s.push(i);
       }
       //reverse(v.begin(),v.end());
       for(int i=0;i<v.size();i++){
          v[i]=i-v[i];
       }
       return v;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
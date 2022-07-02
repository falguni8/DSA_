#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n),a(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int j=0;
    priority_queue<int,vector<int>,greater<int>>p;
    for(int i=0;i<n;i++){
        p.push(v[i]);
        if(p.size()==k){
            a[j]=0;
            a[j]=p.top();
            j++;
            p.pop();
        }
    }
    while(p.size()>0){
            a[j]=0;
            a[j]=p.top();
            j++;
            p.pop();
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
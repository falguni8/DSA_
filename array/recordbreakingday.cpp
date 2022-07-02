#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int todo(int *arr,int n){
    int mx=INT_MIN;
    int ans=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mx && arr[i]>arr[i+1]){
            ans++;
        }
        mx=max(mx,arr[i]);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    arr[n+1]=-1;
    cout<<todo(arr,n+1);
    return 0;
}
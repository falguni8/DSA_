#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int lsubarray(int *arr,int n){
    int pd=abs(arr[0]-arr[1]);
    int ans=0;
    int l=2;
    for(int i=2;i<n;i++){
        if((arr[i]-arr[i-1]==pd)){
            l++;
            pd=abs(arr[i]-arr[i-1]);
            //ans=max(l,ans);
        }
        else{
            pd=abs(arr[i]-arr[i-1]);
            l=2;
        }
        ans=max(l,ans);
        //cout<<ans<<" "<<l<<"\n";
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<lsubarray(arr,n);
    return 0;
}
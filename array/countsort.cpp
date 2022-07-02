#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void countsort(int *arr,int mx,int n){
    int a[mx+1];
    for(int i=0;i<=mx;i++){
        a[i]=0;
    }
    for(int i=0;i<n;i++){
        a[arr[i]]++;
    }
    for(int i=1;i<=mx;i++){
        a[i]+=a[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--a[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int *arr=new int [n];
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mx=max(arr[i],mx);
    }
    cout<<mx<<"\n";
    countsort(arr,mx,n);
    return 0;
}
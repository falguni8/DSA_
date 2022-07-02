#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int uniquenumber(int arr[],int n){
    int k=arr[0];
    for(int i=1;i<n;i++){
        k=k^arr[i];
    }
    return k;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<uniquenumber(arr,n);
    return 0;
}
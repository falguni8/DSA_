#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void subarraysum(int *arr,int n){
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            cout<<sum<<" ";
        }
    }
    cout<<"\n";
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    subarraysum(arr,n);
    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void subset(int n,int arr[]){
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i &(1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<"\n";
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    subset(n,arr);
    return 0;
}
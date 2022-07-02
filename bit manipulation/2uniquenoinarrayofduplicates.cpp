#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool setbit(int a,int pos){
    return a & (1<<pos);
}
int uniquenumber(int arr[],int n){
    int k=0;
    for(int i=0;i<n;i++){
        k=k^arr[i];
    }
    int pos=0;
    int set=0;
    int m=k;
    while(set!=1){
        set=k&1;
        pos++;
        k=k>>1;
    }
    int p=0;
    for(int i=0;i<n;i++){
        if(setbit(arr[i],pos-1)){
            p=p^arr[i];
        }
    }
    cout<<p<<"\n";
    cout<<(p^m)<<"\n";
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    uniquenumber(arr,n);
    return 0;
}
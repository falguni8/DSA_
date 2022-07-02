#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool arr[1000000+1];
bool prime(int n){
    for(int i=2;i<=n;i++){
        if(arr[i]==false){
            for(int j=i*i;j<=n;j+=i){
                arr[j]=true;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(arr[i]==0){
            cout<<i<<" ";
        }
    }
}

int main(){
    int n;
    cin>>n;
    cout<<prime(n);
    return 0;
}
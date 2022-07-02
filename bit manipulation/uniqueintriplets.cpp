#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getbit(int a,int pos){
    return a &(1<<pos);
}
int setbit(int a,int pos){
    return a | (1<<pos);
}
int uniquenumber(int arr[],int n){
    int result=0;
    for(int i=0;i<64;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(getbit(arr[j],i)){
                sum++;
            }
        }
        //cout<<sum<<" ";
        if(sum%3!=0){
            result=setbit(result,i);
        }
        //cout<<result<<"\n";
    }
    return result;
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
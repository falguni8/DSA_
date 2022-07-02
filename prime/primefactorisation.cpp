#include<bits/stdc++.h>
#include<iostream>
using namespace std;



void spf(int a){
    int pf[a+1];
    for(int i=2;i<=a;i++){
        pf[i]=i;
    }
    for(int i=2;i<=a;i++){
        if(pf[i]==i){
            for(int j=i*i;j<=a;j+=i){
                if(pf[j]==j){
                    pf[j]=i;
                }
            }
        }
    }
    while(a!=1){
        cout<<pf[a]<<" ";
        a=a/pf[a];
    }
}
int main(){
    int n;
    cin>>n;
    spf(n);
    return 0;
}
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int egcd(int a,int b){
    if(a==0){
        return b;
    }
    else{
        egcd(b%a,a);
    }
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<egcd(min(a,b),max(a,b));
    return 0;
}
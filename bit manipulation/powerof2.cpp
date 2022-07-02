#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool ispowerof2(int n){
    if(n==0){
        return false;
    }
    return !(n & (n-1));
}

int main(){
    int n;
    cin>>n;
    if(ispowerof2(n)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}
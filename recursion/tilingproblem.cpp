#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int no_of_tiles(int n){
    if(n==0){
        return 0;
    }
    if(n==1 ||n==2){
        return n;
    }
    return no_of_tiles(n-1)+no_of_tiles(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<no_of_tiles(n);
    return 0;
}
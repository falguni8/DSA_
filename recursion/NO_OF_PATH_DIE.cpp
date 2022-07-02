#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int countpath(int s,int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int ans=0;
    for(int i=1;i<=6;i++){
        ans+=countpath(s+i,e)
    }
    return ans;
}
int main(){
    countpath(0,3);
    return 0;
}
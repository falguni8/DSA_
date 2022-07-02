#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
int countpath(int sx,int sy,int n){
    if(sx==n-1&& sy==n-1){
        return 1;
    }
    if(sx>=n || sy>=n) {
        return 0;
    }
    return countpath(sx+1,sy,n) + countpath(sx,sy+1,n);
}
int main(){
    cout<<countpath(0,0,4);
    return 0;
}
*/
int countpath(int sx,int sy,int ex,int ey){
    if(sx==ex-1&& sy==ey-1){
        return 1;
    }
    if(sx>=ex || sy>=ey) {
        return 0;
    }
    return countpath(sx+1,sy,ex,ey) + countpath(sx,sy+1,ex,ey);
}
int main(){
    cout<<countpath(0,0,3,3);
    return 0;
}
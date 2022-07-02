#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void towerofhanoi(int n,char src,char dest,char help){
    if(n==0){
        return ;
    }
    
    
    towerofhanoi(n-1,src,help,dest);
cout<<"MOVE FROM"<<src<<" "<<dest<<"\n";

    towerofhanoi(n-1,src,dest,src);
    

}

int main(){
    towerofhanoi(3,'A','C','B');
    return 0;
}
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void freverse(string s){
    if(s.length()==0){
        return ;
    }
    string ros=s.substr(1);
    freverse(ros);
    cout<<s[0];
}

int main(){
    string s;
    cin>>s;
    freverse(s);
    return 0;
}
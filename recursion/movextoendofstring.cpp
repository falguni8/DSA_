#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string movex(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string p=movex(s.substr(1));
    if(ch!='x'){
        return(ch+p);
    }
    else{
        return p+ch;
    }
}
int main(){
    string s;
    cin>>s;
    cout<<movex(s);
    return 0;
}
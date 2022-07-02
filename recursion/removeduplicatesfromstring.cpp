#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
void removeduplicates(string s,vector<char> v){
    if(s.length()==0){
        return;
    }
    if(find(v.begin(),v.end(),s[0])!=v.end()){
        removeduplicates(s.substr(1),v);
    }
    else{
        cout<<s[0];
        v.push_back(s[0]);
        removeduplicates(s.substr(1),v);
    }
}
*/
string removeduplicates(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string p=removeduplicates(s.substr(1));
    if(ch!=p[0]){
        return(ch+p);
    }
    else{
        return p;
    }
}

int main(){
    string s;
    cin>>s;
    cout<<removeduplicates(s);
    return 0;
}
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void substring(string s,string ans){
    if(s.length()==0){
        cout<<ans<<"\n";
        return;
    }
    char ch=s[0];
    int k=ch;
    string ros=s.substr(1);
    substring(ros,ans);
    substring(ros,ans+ch);
     substring(ros,ans+to_string(k));
}
int main(){
    string s;
    cin>>s;
    string ans;
    substring(s,ans);
    return 0;
}
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void permutation(string s,string ans){
    if(s.length()==0){
        cout<<ans<<"\n";
        return;
    }
   for(int i=0;i<s.length();i++){
       char ch=s[i];
       string ros=s.substr(0,i)+s.substr(i+1);
       permutation(ros,ans+ch);
   }
}
int main(){
    string s;
    cin>>s;
    string ans;
    permutation(s,ans);
    return 0;
} 
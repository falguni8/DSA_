#include<iostream>
#include<stack>
using namespace std;

void reversesentence(string s){
    stack<string>stk;
    for(int i=0;i<s.length();i++){
        string words="";
        while(s[i]!=' ' &&i<s.length()){
            words+=s[i];
            i++;
        }
        stk.push(words);
    }
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<"\n";
}

int main(){
    string s="Hey, how are you doing?";
    reversesentence(s);
    return 0;
}
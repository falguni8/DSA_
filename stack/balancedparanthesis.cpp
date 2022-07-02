#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;



bool balancedparanthesis(string expr){
    
    stack<char> temp;
    for(int i=0;i<expr.length();i++)
    {
        if(temp.empty())
        {
            temp.push(expr[i]);
        }
        else if((temp.top()=='('&& expr[i]==')')  ||  (temp.top()=='{' && expr[i]=='}')  ||  (temp.top()=='[' && expr[i]==']'))
        {
            temp.pop();
        }
        else
        {
            temp.push(expr[i]);
        }
    }
    if(temp.empty())
    {
            return true;
    }
    return false;

}

int main(){

    cout<<balancedparanthesis("{([])}")<<endl;

}
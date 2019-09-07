#include<iostream>
using namespace std;

int precedence(char c);

int main()
{
    int len,top = 0;
    string qexp,stck="(",pexp;
    
    cout<<"Enter the infix expression\n";
    cin>>qexp;
    qexp = qexp + ")";
    len = qexp.length();

    for (int i = 0; i<len; i++)
    {
        if(qexp[i]=='+' || qexp[i]=='-' || qexp[i]=='*' || qexp[i]=='^'  )
        {
            cout<<qexp[i]<<" "<<precedence(qexp[i])<<"\n";
        }
    }
    return 0;
}

int precedence(char ch)
{
    int p;
    
    if(ch == '^')
        p = 3;
    else if(ch == '/' || ch == '*')
        p = 2;
    else if(ch == '+' || ch == '-')
        p = 1;
    else
        p = 0;
    
    return p ;
}


#include<iostream>
using namespace std;

int pred(char c);

int main()
{
    int len,top = 0;
    string q,stck,p = "";

    stck[top]='(';
    cout<<"Enter the infix expression\n";
    cin>>q;
    q = q + ')';
    len = q.length();

    for (int i = 0; i<len; i++)
    {
        if(q[i]=='+'|| q[i]=='^' || q[i]=='-' || q[i]=='*' || q[i]=='/')
        {
            while (pred(q[i])<=pred(stck[top]))
            {
                p = p + stck[top];
                top--;
            }

            if(pred(q[i])>pred(stck[i]))
            {
                top++;
                stck[top] = q[i];
            }
        }

        else if(q[i]==')' || q[i]=='(')
        {
            if(q[i]=='(')
            {
                top++;
                stck[top] = q[i];
            }
            else
            {
                while (stck[top]!='(')
                {
                    p = p + stck[top];
                    top--;
                }
                top--;
            }  
        }
        else
            p = p +q[i];
    }
    cout<<p;

    return 0;
}

int pred(char ch)
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
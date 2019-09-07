//
// Created by HP on 23-Jan-18.
//
//
// Created by HP on 23-Jan-18.
//
//
// Created by HP on 23-Jan-18.
//,,,,,,,,,,left rotation.,,,,,,,,,,,,,,,

#include<iostream>
using namespace std;

int main(void)
{
    int i=0,j=0,rotation,size;
    cin>>size>>rotation;
    int a[size];
    for(i=0;i<size;i++)
        cin>>a[i];
    for(i=1;i<=rotation;i++)
    {   int temp=a[0];
        for(j=0;j<size-1;j++)
            a[j]=a[j+1];
        a[j]=temp;
    }

    for(i=0;i<size;i++)
        cout<<a[i]<<" ";

    return 0;
}


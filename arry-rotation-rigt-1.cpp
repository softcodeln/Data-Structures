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

    j= rotation%size;

    for(i=0;i<size;i++){
        cin>>a[j];
        j=(j+1)%size;
    }
    for(i=0;i<size;i++)
        cout<<a[i]<<" ";

    return 0;
}


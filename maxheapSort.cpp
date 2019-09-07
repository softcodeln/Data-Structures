#include<iostream>
using namespace std;

void heapsort(int a[],  int);
void buildHeap(int a[], int, int);
void maxheapify(int a[], int, int);

int main()
{
    int i,n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        heapsort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    }
    return 0;
}

void heapsort(int a[], int n)
{
    int heapsize = n-1;
    buildHeap(a, n, heapsize);
    
    for(int i=n-1;i>=1;i--)
    {
        swap(a[i],a[0]);
        heapsize -=1;
        maxheapify(a,0,heapsize);
    }
}

void buildHeap(int a[],int n, int heapsize)
{
    for(int i = (n/2)-1;i>=0;i--)
    {
        maxheapify(a,i,heapsize);
    }
}

void maxheapify(int a[],int i, int heapsize)
{
    int l,r,largest=-1;
    l = 2*i+1;
    r = 2*i+2;

    if(l<=heapsize && a[l]>a[i])
        largest = l;
    else
        largest = i;

    if(r<=heapsize && a[l]<a[r])
        largest = r;

    if(largest != i)
    {
        swap(a[i],a[largest]);
        maxheapify(a,largest, heapsize);
    }
}
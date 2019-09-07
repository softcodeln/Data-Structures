//
// Created by HP on 24-Jan-18.
//
#include<stdio.h>
int main(void)
{
    int i,n,e,j,t;
    printf("enter number of elements of array\n");
    scanf("%d",&n);
    int arr[n],lb = 0,ub = n,k = 0;
    printf("enter elements of array\n");
    for(i = 0;i < n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("unsorted array is :");
    for(i = 0;i < n;i++) {
        printf("%4d",arr[i]);
    }
    for(i =0;i < n;i++) {
        for(j = 0;j < n-i-1;j++)
        {
            if(arr[j]>arr[j+1]) {
                t = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = t;
            }
        }
    }
    printf("\nsorted array is :");
    for(i = 0;i < n;i++) {
        printf("%4d",arr[i]);
    }
    printf("\nenter element which you want to search\n");
    scanf("%d",&e);
    int mid = (lb + ub)/2;
    while(mid > 0) {
        if(arr[mid] == e) {
            k = 1;
            break;
        }
        if(e < arr[mid]) {
            ub = mid;
        }
        if(e > arr[mid]) {
            lb = mid;
        }
        mid = (ub + lb)/2;
    }
    if(k == 1)
        printf("element %d found at %d position in given sorted array.\n",e,mid+1);
    else
        printf("element %d not found in given array\n",e);
    return 0;
}
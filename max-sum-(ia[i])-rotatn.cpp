//
// Created by HP on 24-Jan-18.
//
#include<iostream>
using namespace std;

int maxSum( int a[] , int n ){
    int i = 0 , k , max , SumRotation = 0 , arraySum = 0;
   cout << "enter elements of array \n ";
     k = n ;
    while ( k-- ) {
        cin >> a[i];
        arraySum = arraySum + a[i];
        SumRotation = SumRotation + i * a[i];
        i++;
    }
    max = SumRotation  ;
    for( i = 1 ; i < n ; i++){
        SumRotation = SumRotation + arraySum - n * a[n-i];

        if(max < SumRotation )
           max = SumRotation ;
    }
    return max ;
}
int main(void)
{
    int n , c ;
    cout << "enter size of array\n";
    cin >> n ;
    int a[n] ;
    c = maxSum( a , n );
    cout << " maximum value of Sum( i*arr[i]) with only rotations on given array " << c ;

    return 0;
}

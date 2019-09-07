//
// Created by HP on 25-Jan-18.
//
#include<iostream>
using namespace std;

int gcd_euclidean_estimation ( int a , int b , int *x , int *y ){
    if( a == 0){
         *x = 0 ;
         *y = 1 ;
        return b ;
    }
    int x1 = 1 , y1 = 1 ;
    int gcd = gcd_euclidean_estimation( b%a ,a , &x1 , & y1 );
    *x = y1 - ( b / a) * x1 ;
    *y = x1 ;

    return gcd ;
}

int main(void)
{
    int  gcd , x = 1 , y = 1 , a , b ;
    cin >> a >> b ;
   gcd =  gcd_euclidean_estimation( a , b , &x , &y ) ;
    cout << "GCD( "<< a << " " << b <<" ) = " << gcd ;
    return 0;
}

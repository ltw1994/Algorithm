//
//  main.cpp
//  Algorithm_cpp
//
//  Created by 임태완 on 2019. 7. 15..
//  Copyright © 2019년 임태완. All rights reserved.
//

#include <iostream>

long A[92] ;
long n ;
int count = 2 ;

int main() {
    //std :: cout << 2 ;
    A[0] = 0 ;
    A[1] = 1 ;
    std:: cin >>  n ;
    if (n == 0)
        std:: cout << 0;
    if (n == 1)
        std:: cout << 1;
    else{
        while(count <= n ) {
            A[count] = A[count-1] + A[count-2] ;
            if (count == n)
               //std:: cout << A ;
                std:: cout << A[count] ;
            count ++ ;
        }
    }
    
}

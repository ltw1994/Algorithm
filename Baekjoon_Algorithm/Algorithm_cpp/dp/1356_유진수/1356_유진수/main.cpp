//
//  main.cpp
//  1356_유진수
//
//  Created by 임태완 on 2019. 10. 7..
//  Copyright © 2019년 임태완. All rights reserved.
//

#include <iostream>
using namespace std ;

int main() {
    
    string N ;
    int cnt ;
    cin >> N ;
    bool result = false ;
    
    cnt = 1 ;
    while(cnt <= N.length()) {
        
        if(N.length() == 1) {
            break ;
        }
        int num1 = 1 ;
        int num2 = 1 ;
        string str1 = "" ;
        string str2 = "" ;
        char ch1 ;
        char ch2 ;
        for(int i = 0 ; i < cnt ; i++) {
            str1 += N[i] ;
        }
        for(int i = cnt ; i < N.length() ; i++) {
            str2 += N[i] ;
        }
        
        
    //    cout << "str1 = " << str1 << " str2 = " << str2 << endl ;

        
        for(int i = 0 ; i < str1.length() ; i++) {
            ch1 = str1[i] ;
            num1 *= int(ch1) - '0' ;
        }
        for(int i = 0 ; i < str2.length() ; i++){
            ch2 = str2[i] ;
            num2 *= int(ch2) - '0' ;
        }
        if (num1 == num2) {
            result = true ;
            break ;
        }
        cnt += 1 ;
        
       // cout << "num1 = " << num1 << " num2 = " << num2 << endl ;
    }
    
    if (result) cout << "YES" ;
    else cout << "NO" ;

}

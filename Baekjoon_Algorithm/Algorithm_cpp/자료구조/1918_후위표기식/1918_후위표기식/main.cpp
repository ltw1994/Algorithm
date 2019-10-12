//
//  main.cpp
//  1918_후위표기식
//
//  Created by 임태완 on 2019. 10. 11..
//  Copyright © 2019년 임태완. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std ;

stack<char> nums ;
stack<char> opers ;

int main() {
    string str ;
    string result = "" ;
    cin >> str ;
    int cnt = 0 ;
    while(cnt < str.length()) {
        //cout << result << endl ;
        
        if (str[cnt] == '(') {
            opers.push(str[cnt]) ;
        }
        else if (str[cnt] == ')') {
            while(opers.top() != '(') {
                result += opers.top() ;
                opers.pop() ;
            }
            opers.pop() ;
        }
        else if (str[cnt] == '/' || str[cnt] == '*') {
            while(!opers.empty() && (opers.top() == '*' || opers.top() == '/')){
                result += opers.top() ;
                opers.pop() ;
            }
            opers.push(str[cnt]) ;

        }
        else if (str[cnt] == '+' || str[cnt] == '-') {
            while(!opers.empty() && opers.top() != '('){
                result += opers.top() ;
                opers.pop() ;
            }
            opers.push(str[cnt]) ;

        }
        else {
            result += str[cnt] ;
        }
        cnt += 1 ;
    }
    while(opers.size() > 0) {
        //cout << opers.top() << endl ;
        result += opers.top() ;
        opers.pop() ;
    }
    cout << result ;
    return 0 ;
}

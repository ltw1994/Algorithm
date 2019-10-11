//
//  main.cpp
//  16637_괄호추가하기
//
//  Created by 임태완 on 2019. 10. 11..
//  Copyright © 2019년 임태완. All rights reserved.
//

#include <iostream>

using namespace std ;
int N ;
string str ;
int num[10] ;
char oper[10] ;
int mx = -1000000001 ;


int calculator(int a, int b, char o) {
    if (o == '+') return a + b ;
    else if (o == '-') return a - b ;
    else return a * b ;
    
}

int DFS(int idx, int cnt) {
    //cout << endl ;
    //cout << idx << " " << cnt << endl ;
    
    if (N == 1) return num[0];
    if (N == 3) return calculator(num[0], num[1], oper[0]);
    if (cnt > N/2-1) {
        if (idx > mx) mx = idx ;
        //cout << "MX" << mx ;
        return mx ;
    }
    int temp, tmp ;
    temp = calculator(idx, num[cnt+1], oper[cnt]) ;
    DFS(temp, cnt+1) ;
    if (cnt < str.length() / 2 - 1) {
        tmp = calculator(num[cnt+1], num[cnt+2], oper[cnt+1]) ;
        temp = calculator(idx, tmp, oper[cnt]) ;
        DFS(temp, cnt+2) ;
    }
    return mx ;
}

int main() {
    
    cin >> N ;
    cin >> str ;
    int result ; 
//    cout << " " << str.length()/2-1 ;
    for (int i = 0 ; i < str.length()/2 ; i++) {
//        cout << i ;
        num[i] = int(str[2 * i] -'0') ;
        oper[i] = str[2 * i + 1 ] ;
    }
    num[N/2] = int(str[str.length()-1]-'0') ;
//    cout << num[0] << num[1] << num[2] << num[3] << num[4] << endl ; ;
//    cout << oper[0] << oper[1] << oper[2] << oper[3] << endl ;
    result = DFS(num[0], 0) ;
    cout << result ;
    return 0;
}

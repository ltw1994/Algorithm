//
//  main.cpp
//  1549_K
//
//  Created by 임태완 on 2019. 10. 7..
//  Copyright © 2019년 임태완. All rights reserved.
//

#include <iostream>
using namespace std ;

long long A[3001] ;

long long game(long long a, long long b) {
    long long result = 0 ;
    for(int k = 0 ; k < b ; k++) {
        result += A[a+k] ;
//        cout << endl ;
//        cout << "@" << a+k << endl ;
    }
    return result ;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N ;
    cin >> N ;
    long long mn = 1000000001 ;
    long long res = 0 ;
    
    for(int i = 0 ; i < N ; i++) {
        cin >> A[i] ;
    }
    
    int cnt = 0 ;
    
    while(cnt < N) {
        long long num1, num2 ;
        for(int i = 1 ; i + cnt < N ; i++) {
            if (cnt + 2 * i > N ) break ;
            num1 = game(cnt, i) ;
            for(int j = i ; cnt + j < N - i + 1; j++)
            {
              //  cout << cnt + j << endl ;
                num2 = game(cnt+j , i) ;
                //cout << "i = " << cnt << " j = " << cnt + j << " k = " << i << " num1 = " << num1 << "num2 = " << num2 << endl ;//

                if (abs(num2 - num1) <= mn) {
                    res = i ;
                    mn = abs(num2 - num1) ;
                }
            }
        }
        cnt += 1 ;
    }
    cout << res << endl ;
    cout << mn ;
    return 0;
}
    


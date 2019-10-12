//
//  main.cpp
//  14501_퇴사
//
//  Created by 임태완 on 2019. 10. 10..
//  Copyright © 2019년 임태완. All rights reserved.
//

#include <iostream>

using namespace std ;

int T[16] ;
int P[16] ;
int D[16] ;
int result = 0 ;

int main() {
    
    int N ;
    cin >> N ;
    for(int i = 0 ; i < N ; i++) {
        cin >> T[i] >> P[i] ;
    }
    
    for(int i = 0 ; i < N+1 ; i++) {
        for(int j = 0 ; j < i ; j++) {
            D[i] = max(D[i], D[j]) ;
            
            if (j + T[j] == i) {
                D[i] = max(D[i], D[j] + P[j]) ;
            }
        }
        result = max(result, D[i]) ;
    }
    cout << result ;
    
    return 0;
}

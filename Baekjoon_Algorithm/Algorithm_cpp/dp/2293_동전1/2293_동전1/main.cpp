//
//  main.cpp
//  2293_동전1
//
//  Created by 임태완 on 2019. 10. 11..
//  Copyright © 2019년 임태완. All rights reserved.
//

#include <iostream>

using namespace std ;

int D[10002] ;
int coins[102] ;
int main() {
    int n, k ;
    cin >> n >> k ;
    for(int i = 0 ; i < n ; i++) {
        cin >> coins[i] ;
    }
    D[0] = 1 ;
    //cout << D[0] << D[1] << D[2] << D[3] << D[4] << D[5] << endl ;
    for(int i = 0 ; i < n ; i++) {
        for (int j = coins[i] ; j < k+1 ; j++) {
            D[j] += D[j-coins[i]] ;
        }
    }
    cout << D[k] ;
    
    return 0;
}

//
//  main.cpp
//  15999_뒤집기
//
//  Created by 임태완 on 2019. 9. 5..
//  Copyright © 2019년 임태완. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std ;

int N, M ;
const int dx[] = {1, 0, -1, 0} , dy[] = {0, -1, 0 , 1} ;
char graph[2001][2001] ;
string tmp ;
int result  ;

void game() {
    int nx, ny ;
    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < M ; j++){
            cout << result << " " ;
            for (int k = 0 ; k < 4 ; k++){
                nx = j + dx[k] ;
                ny = i + dy[k] ;
                if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue ;
                if (graph[i][j] != graph[ny][nx]) {
                    result -= 1 ;
                    break ;
                }
                
            }
        }
    }
}

int main() {
    cin >> N >> M ;
    for (int i = 0 ; i < N ; i++){
        cin >> tmp ;
        for (int j = 0 ; j < M ; j++){
            graph[i][j] = tmp[j] ;
        }
    }
    result = M * N ;
    game() ;

    int a ;
    a = pow(2,result) ;

    
    a %= 1000000007 ;
    cout << a ;
    
    return 0;
}
/*
3 4
WWWW
WWWW
BWBW
 */

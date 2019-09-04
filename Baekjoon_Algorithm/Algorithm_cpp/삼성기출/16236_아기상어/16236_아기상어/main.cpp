//
//  main.cpp
//  16236_아기상어
//
//  Created by 임태완 on 2019. 9. 2..
//  Copyright © 2019년 임태완. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std ;

struct now {
    int xx, yy ;
}

queue<now> q ;
int x ;
int y ;
int N ;
int sea[21][21] ;

const int dx[] = {1, 0, -1, 0} , dy[] = {0, -1, 0, 1} ;

void find_fish() {
    x = q.front().xx ;
    y = q.front().yy ;
    
}

void BFS() {
    x = q.front().xx ;
    y = q.front().yy ;
}


int main() {
    
    cin >> N ;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++){
            cin >> sea[i][j] ;
            if (sea[i][j] == 9) {
                q.push({i, j}) ;
                sea[i][j] = 0 ;
                
            }
        }
    }
    return 0;
}

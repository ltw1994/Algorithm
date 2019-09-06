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
    int yy, xx, size, eat, clk ;
};

queue<now> q ;
int x, y, N, s, e, c ;
int result ;
bool Call_Mother = false ;
int sea[21][21] ;
bool visited[21][21] ;

const int dx[] = {0, -1, 1, 0} , dy[] = {-1, 0, 0, 1} ;

void find_fish() {
    Call_Mother = true ;
    s = q.front().size ;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            if (sea[i][j] < s) Call_Mother = false ;
        }
     }
    
}

void BFS() {
    int nx, ny ;
    if (q.size() == 0) {
        Call_Mother = true ;
        return ;
    }
    x = q.front().xx ;
    y = q.front().yy ;
    s = q.front().size ;
    e = q.front().eat ;
    c = q.front().clk ;
    visited[y][x] = true ;
    cout << "x = " << x <<" y = " << y << " size = " << s << " eat = " << e << " clk = " << c << endl ;
    q.pop() ;
    c += 1 ;
    for (int i = 0 ; i < 4 ; i++){
        nx = x + dx[i] ;
        ny = y + dy[i] ;
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || sea[ny][nx] > s || visited[ny][nx] == true) continue ;
        else {
            visited[ny][nx] = true ;
            if (sea[ny][nx] < s && sea[ny][nx] > 0) {
                e += 1 ;
                if (s == e) {
                    s += 1 ;
                    e = 0 ;
                }
                while( !q.empty() ) q.pop();
                q.push({ny, nx, s, e, c}) ;
                result = c ;
                cout << "tmpresult = " << result << endl ;
                sea[ny][nx] = 0 ;
                cout << " -------find!!!-------" << endl ;
                find_fish() ;
                return ;
            }
            else {
       //         cout << "(" << nx << "," << ny << ") 넣는다." << endl ;
                q.push({ny, nx, s, e, c}) ;
            }
        }
    }
    BFS() ;
}
                       

void solve() {
    while(true) {
        if (Call_Mother == true) {
            return ;
        }
        else {
            for (int i = 0 ; i < N ; i++) {
                for (int j = 0 ; j < N ; j++) {
                    visited[i][j] = false ;
                }
            }
//            int a, b ;
//            a = q.front().xx ;
//            b = q.front().yy ;
//            visited[b][a] = true ;
            BFS() ;
        }
    }
    
}


int main() {
    
    cin >> N ;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++){
            cin >> sea[i][j] ;
            if (sea[i][j] == 9) {
                q.push({i, j, 2, 0, 0}) ;
                sea[i][j] = 0 ;
            }
        }
    }
    solve() ;
//    for (int i = 0 ; i < N ; i++) {
//        for (int j = 0 ; j < N ; j++) {
//            cout << sea[i][j] << " ";
//        }
//        cout << endl ; 
//    }
    cout  << result ;
    return 0;
}

//
//  main.cpp
//  13460_구슬탈출2
//
//  Created by 임태완 on 2019. 10. 3..
//  Copyright © 2019년 임태완. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std ;
int N, M ;
int result ;
char graph[11][11] ;
struct node{
    int dir ;
    int cnt ;
    int rx ;
    int ry ;
    int bx ;
    int by ;
};
queue <node> q ;

void right() {
    node now ;
    now = q.front() ;
    cout << "right" << " " << now.rx << " " << now.ry << " " << now.bx << " " << now.by << endl ;

    int cnt, newrx = 0, newry = 0, newbx = 0, newby = 0 ;
    cnt = now.cnt ;
    if (now.bx > now.rx) {
        for(int i = now.bx ; i < M ; i++) {
            if(graph[now.by][i] == '#' || graph[now.by][i] == 'R') {
                newbx = i-1 ;
                newby = now.by ;
                break ;
            }
            else if(graph[now.by][i] == 'O'){
                result = -1  ;
                return ;
            }
            newbx = M-1 ;
            newby = now.by ;
        }
        graph[now.by][now.bx] = '.' ;
        graph[newby][newbx] = 'B' ;
        for(int i = now.rx ; i < M ; i++) {
            if(graph[now.ry][i] == '#' || graph[now.ry][i] == 'B') {
                newrx = i-1 ;
                newry = now.ry ;
                break ;
            }
            else if(graph[now.ry][i] == 'O'){
                result = now.cnt + 1  ;
                return ;
            }
            newrx = M-1 ;
            newry = now.by ;
        }
        graph[now.ry][now.rx] = '.' ;
        graph[newry][newrx] = 'R' ;
    }
    else {
        for(int i = now.rx ; i < M ; i++) {
            if(graph[now.ry][i] == '#' || graph[now.ry][i] == 'B') {
                newrx = i-1 ;
                newry = now.ry ;
                break ;
            }
            else if(graph[now.ry][i] == 'O'){
                result = now.cnt + 1  ;
                return ;
            }
            newrx = M-1 ;
            newry = now.ry ;
        }
        graph[now.ry][now.rx] = '.' ;
        graph[newry][newrx] = 'R' ;
        for(int i = now.bx ; i < M ; i++) {
            if(graph[now.by][i] == '#' || graph[now.by][i] == 'R') {
                newbx = i-1 ;
                newby = now.by ;
                break ;
            }
            else if(graph[now.by][i] == 'O'){
                result = -1  ;
                return ;
            }
            newbx = M-1 ;
            newby = now.by ;
        }
        graph[now.by][now.bx] = '.' ;
        graph[newby][newbx] = 'B' ;
    }

    q.push({0, cnt+1 ,newrx, newry, newbx, newby}) ;
    q.push({1, cnt+1 ,newrx, newry, newbx, newby}) ;
    q.push({2, cnt+1 ,newrx, newry, newbx, newby}) ;
    q.push({3, cnt+1 ,newrx, newry, newbx, newby}) ;
}

void left() {
    
    node now ;
    now = q.front() ;
    int cnt, newrx = 0, newry = 0, newbx = 0, newby = 0 ;
    cnt = now.cnt ;
    cout << "left" << " " << now.rx << " " << now.ry << " " << now.bx << " " << now.by << endl ;

    if (now.bx > now.rx) {
        for(int i = now.rx ; i >= 0 ; i--) {
            if(graph[now.ry][i] == '#' || graph[now.ry][i] == 'B') {
                newrx = i+1 ;
                newry = now.ry ;
                break ;
            }
            else if(graph[now.ry][i] == 'O'){
                result = now.cnt + 1 ;
                return ;
            }
            newrx = 0 ;
            newry = now.ry ;
        }
        graph[now.ry][now.rx] = '.' ;
        graph[newry][newrx] = 'R' ;
        
        for(int i = now.bx ; i >= 0 ; i--) {
            if(graph[now.by][i] == '#' || graph[now.by][i] == 'R') {
                newbx = i+1 ;
                newby = now.by ;
                break ;
            }
            else if(graph[now.by][i] == 'O'){
                result = -1 ;
                return ;
            }
            newbx = 0 ;
            newby = now.by ;
        }
        graph[now.by][now.bx] = '.' ;
        graph[newby][newbx] = 'B' ;
    }
    else {
        for(int i = now.bx ; i >= 0 ; i--) {
            if(graph[now.by][i] == '#' || graph[now.by][i] == 'R') {
                newbx = i+1 ;
                newby = now.by ;
                break ;
            }
            else if(graph[now.by][i] == 'O'){
                result = -1 ;
                return ;
            }
            newbx = 0 ;
            newby = now.by ;
        }
        graph[now.by][now.bx] = '.' ;
        graph[newby][newbx] = 'B' ;
        for(int i = now.rx ; i >= 0 ; i--) {
            if(graph[now.ry][i] == '#' || graph[now.ry][i] == 'B') {
                newrx = i+1 ;
                newry = now.ry ;
                break ;
            }
            else if(graph[now.ry][i] == 'O'){
                result = now.cnt + 1 ;
                return ;
            }
            newrx = 0 ;
            newry = now.by ;
        }
        graph[now.ry][now.rx] = '.' ;
        graph[newry][newrx] = 'R' ;
    }
    q.push({0, cnt+1 ,newrx, newry, newbx, newby}) ;
    q.push({1, cnt+1 ,newrx, newry, newbx, newby}) ;
    q.push({2, cnt+1 ,newrx, newry, newbx, newby}) ;
    q.push({3, cnt+1 ,newrx, newry, newbx, newby}) ;
}

void up() {
    node now ;
    now = q.front() ;
    int cnt, newrx = 0, newry = 0, newbx = 0, newby = 0 ;
    cnt = now.cnt ;
    cout << "up" << " " << now.rx << " " << now.ry << " " << now.bx << " " << now.by << endl ;
    if (now.by > now.ry) {
        for(int i = now.ry ; i >= 0 ; i--) {
            if(graph[i][now.rx] == '#' || graph[i][now.rx] == 'B') {
                newry = i + 1;
                newrx = now.rx ;
                break ;
            }
            else if(graph[i][now.rx] == 'O'){
                result = now.cnt + 1  ;
                return ;
            }
            newrx = now.rx ;
            newry = 0 ;
        }
        graph[now.ry][now.rx] = '.' ;
        graph[newry][newrx] = 'R' ;
        for(int i = now.by ; i >= 0 ; i--) {
            if(graph[i][now.bx] == '#' || graph[i][now.bx] == 'R') {
                newby = i + 1;
                newbx = now.bx ;
                break ;
            }
            else if(graph[i][now.bx] == 'O'){
                result = -1 ;
                return ;
            }
            newbx = now.bx ;
            newby = 0 ;
        }
        graph[now.by][now.bx] = '.' ;
        graph[newby][newbx] = 'B' ;
    }
    else {
        for(int i = now.by ; i >= 0 ; i--) {
            if(graph[i][now.bx] == '#' || graph[i][now.bx] == 'R') {
                newby = i + 1;
                newbx = now.bx ;
                break ;
            }
            else if(graph[i][now.bx] == 'O'){
                result = -1  ;
                return ;
            }
            newbx = now.bx ;
            newby = 0 ;
        }
        graph[now.by][now.bx] = '.' ;
        graph[newby][newbx] = 'B' ;
        for(int i = now.ry ; i >= 0 ; i--) {
            if(graph[i][now.rx] == '#' || graph[i][now.rx] == 'B') {
                newry = i + 1;
                newrx = now.rx ;
                break ;
            }
            else if(graph[i][now.rx] == 'O'){
                result = now.cnt + 1  ;
                return ;
            }
            newrx = now.rx ;
            newry = 0 ;
        }
        graph[now.ry][now.rx] = '.' ;
        graph[newry][newrx] = 'R' ;
    }
    q.push({0, cnt+1 ,newrx, newry, newbx, newby}) ;
    q.push({1, cnt+1 ,newrx, newry, newbx, newby}) ;
    q.push({2, cnt+1 ,newrx, newry, newbx, newby}) ;
    q.push({3, cnt+1 ,newrx, newry, newbx, newby}) ;
}

void down() {
    node now ;
    now = q.front() ;
    int cnt, newrx = 0, newry = 0, newbx = 0, newby = 0 ;
    cnt = now.cnt ;
    cout << "down" << " " << now.rx << " " << now.ry << " " << now.bx << " " << now.by << endl ;

    if (now.by > now.ry) {
        for(int i = now.by ; i < N ; i++) {
            if(graph[i][now.bx] == '#' || graph[i][now.bx] == 'R') {
                newby = i - 1;
                newbx = now.bx ;
                break ;
            }
            else if(graph[i][now.bx] == 'O'){
                result = -1  ;
                return ;
            }
            newbx = now.bx ;
            newby = 0 ;
        }
        graph[now.by][now.bx] = '.' ;
        graph[newby][newbx] = 'B' ;
        for(int i = now.ry ; i < N ; i++) {
            if(graph[i][now.rx] == '#' || graph[i][now.rx] == 'B') {
                newry = i - 1;
                newrx = now.rx ;
                break ;
            }
            else if(graph[i][now.rx] == 'O'){
                result = now.cnt + 1  ;
                return ;
            }
            newrx = now.rx ;
            newry = 0 ;
        }
        graph[now.ry][now.rx] = '.' ;
        graph[newry][newrx] = 'R' ;
    }
    else {
        for(int i = now.ry ; i < N ; i++) {
            if(graph[i][now.rx] == '#' || graph[i][now.rx] == 'B') {
                newry = i - 1;
                newrx = now.rx ;
                break ;
            }
            else if(graph[i][now.rx] == 'O'){
                result = now.cnt + 1  ;
                return ;
            }
            newrx = now.rx ;
            newry = 0 ;
        }
        graph[now.ry][now.rx] = '.' ;
        graph[newry][newrx] = 'R' ;
        for(int i = now.by ; i < N ; i++) {
            if(graph[i][now.bx] == '#' || graph[i][now.bx] == 'R') {
                newby = i - 1;
                newbx = now.bx ;
                break ;
            }
            else if(graph[i][now.bx] == 'O'){
                result = -1 ;
                return ;
            }
            newbx = now.bx ;
            newby = 0 ;
        }
        graph[now.by][now.bx] = '.' ;
        graph[newby][newbx] = 'B' ;
    }

    q.push({0, cnt+1 ,newrx, newry, newbx, newby}) ;
    q.push({1, cnt+1 ,newrx, newry, newbx, newby}) ;
    q.push({2, cnt+1 ,newrx, newry, newbx, newby}) ;
    q.push({3, cnt+1 ,newrx, newry, newbx, newby}) ;
}

void print() {
    for (int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            cout << graph[i][j] << " " ;
        }
        cout << endl ;
    }
}

void game() {
    while(true) {
        print() ;
        node now ;
        int d;
        now = q.front() ;
        d = now.dir ;
        if (d == 0) {
            right() ;
            q.pop() ;
        }
        else if (d == 1) {
            left() ;
            q.pop() ;
        }
        else if (d == 2) {
            down() ;
            q.pop() ;
        }
        else {
            up() ;
            q.pop() ;
        }
        if (result != 0) {
            return ;
        }
    }
    cout << endl ;
}
int main() {
    string line ;
    cin >> N >> M ;
    result = 0 ;
    int irx, iry, ibx, iby;
    for (int i = 0 ; i < N ; i++) {
        cin >> line ;
        for(int j = 0 ; j < M ; j++) {
            graph[i][j] = line[j] ;
        }
    }
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++){
            if (graph[i][j] == 'R') {
                irx = j ;
                iry = i ;
            }
            if (graph[i][j] == 'B') {
                ibx = j ;
                iby = i ;
            }
        }
    }
    q.push({0, 0 ,irx, iry, ibx, iby}) ;
    q.push({1, 0 ,irx, iry, ibx, iby}) ;
    q.push({2, 0 ,irx, iry, ibx, iby}) ;
    q.push({3, 0 ,irx, iry, ibx, iby}) ;

    game() ;
    cout << result ; 
    return 0;
}

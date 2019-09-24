//
//  main.cpp
//  14500_테트로미노
//
//  Created by 임태완 on 2019. 9. 24..
//  Copyright © 2019년 임태완. All rights reserved.
//

#include <iostream>
using namespace std ;

int map[501][501] ;
int N, M ;
int mx, result ;

const int dx1[] = {0, 1, 2, 3} ;
const int dy1[] = {0, 0, 0, 0} ;
const int dx2[] = {0, 1, 0, 1} ;
const int dy2[] = {0, 0, -1, -1} ;
const int dx3[] = {0, 0, 0, 1} ;
const int dy3[] = {0, -1, -2, -2} ;
const int dx4[] = {0, 0, 1, 1} ;
const int dy4[] = {0, -1, -1, -2} ;
const int dx5[] = {0, 1, 2, 1} ;
const int dy5[] = {0, 0, 0, -1} ;
const int dx6[] = {0, 0, 0, 0} ;
const int dy6[] = {0, 1, 2, 3} ;
const int dx7[] = {0, 1, 2, 0} ;
const int dy7[] = {0, 0, 0, -1} ;
const int dx8[] = {0, 1, 1, 1} ;
const int dy8[] = {0, 0, -1, -2} ;
const int dx9[] = {0, -2, -1, 0} ;
const int dy9[] = {0, -1, -1, -1} ;
const int dx10[] = {0, 1, -1, 0} ;
const int dy10[] = {0, 0, -1, -1} ;
const int dx11[] = {0, 0, 1, 0} ;
const int dy11[] = {0, 1, 1, 2} ;
const int dx12[] = {0, -1, 0, 1} ;
const int dy12[] = {0, -1, -1, -1} ;
const int dx13[] = {0, -1, 0, 0} ;
const int dy13[] = {0, -1, -1, -2} ;
const int dx14[] = {0, 0, 0, -1} ;
const int dy14[] = {0, -1, -2, -2} ;
const int dx15[] = {0, 1, 2, 2} ;
const int dy15[] = {0, 0, 0, -1} ;
const int dx16[] = {0, 1, 0, 0} ;
const int dy16[] = {0, 0, -1, -2} ;
const int dx17[] = {0, 0, 1, 2} ;
const int dy17[] = {0, -1, -1, -1} ;
const int dx18[] = {0, -1, 0, -1} ;
const int dy18[] = {0, -1, -1, -2} ;
const int dx19[] = {0, 1, 1, 2 } ;
const int dy19[] = {0, 0, -1, -1} ;

int game(int y, int x) {
    
    int nx, ny, res, sum ;
    res = 0 ;
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy1[t] ;
        nx = x + dx1[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy2[t] ;
        nx = x + dx2[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy3[t] ;
        nx = x + dx3[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy4[t] ;
        nx = x + dx4[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy5[t] ;
        nx = x + dx5[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy6[t] ;
        nx = x + dx6[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy7[t] ;
        nx = x + dx7[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy2[t] ;
        nx = x + dx2[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy8[t] ;
        nx = x + dx8[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy9[t] ;
        nx = x + dx9[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy10[t] ;
        nx = x + dx10[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy11[t] ;
        nx = x + dx11[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy12[t] ;
        nx = x + dx12[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }

    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy13[t] ;
        nx = x + dx13[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy14[t] ;
        nx = x + dx14[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy15[t] ;
        nx = x + dx15[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy16[t] ;
        nx = x + dx16[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy17[t] ;
        nx = x + dx17[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy18[t] ;
        nx = x + dx18[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    
    sum = 0 ;
    for (int t = 0 ; t < 4 ; t++) {
        ny = y + dy19[t] ;
        nx = x + dx19[t] ;
        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1) {
            break ;
        }
        else {
            sum += map[ny][nx] ;
        }
    }
    if (sum > res) {
        res = sum ;
    }
    
    return res ;
}

int main() {

    cin >> N >> M ;
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            cin >> map[i][j] ;
        }
    }
    mx = 0 ;
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            result = game(i, j) ;
          //  cout << result << endl ;
            if (mx < result) {
                mx = result ;
            }
        }
    }
    
    cout << mx ;
    return 0;
}

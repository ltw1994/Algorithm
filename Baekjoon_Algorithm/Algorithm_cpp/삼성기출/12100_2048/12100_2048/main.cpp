//
//  main.cpp
//  12100_2048
//
//  Created by 임태완 on 2019. 9. 19..
//  Copyright © 2019년 임태완. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <deque>
#include <vector>



using namespace std ;

int N ;
int graph[22][22] ;
int ini_graph[22][22] ;
int result ;
int dfs_lst[5] ;


void print() {
    for (int i = 0 ; i < N ; i++){
        cout << endl ;
        for (int j = 0 ; j < N ; j++){
            cout << graph[i][j] << " " ;
        }
    }
    cout << endl ;
}
void Left() {
    int cnt, idx ;
    for(int i = 0 ; i < N ; i++) {
        cnt = 0 ;
        idx = 0 ;
        while(true) {
            if (idx == N) break ;
            if (idx == N-1 ){
            //else if (graph[i][idx] != 0 && idx == N-1 ){
                graph[i][cnt] = graph[i][idx] ;
                idx += 1 ;
                cnt += 1 ;
            }
            else if (graph[i][idx] == 0) {
                idx += 1 ;
            }
            else if (graph[i][idx] != 0 && graph[i][idx] == graph[i][idx+1]) {
                graph[i][cnt] = 2 * graph[i][idx] ;
                graph[i][idx+1] = 0 ;
                cnt += 1 ;
                idx += 2 ;
            }
            else {
                graph[i][cnt] = graph[i][idx] ;
                idx += 1 ;
                cnt += 1 ;
            }
        }
        for(int j = cnt ; j < N ; j++){
            graph[i][j] = 0 ;
        }
    }
    print() ;
}

void Right() {
    int cnt, idx ;
    for(int i = 0 ; i < N ; i++) {
        cnt = N-1 ;
        idx = N-1 ;
        while(true) {
            if (idx == -1) break ;
            if (idx == 0 ){
            //else if (graph[i][idx] != 0 && idx == 0 ){
                graph[i][cnt] = graph[i][idx] ;
                idx -= 1 ;
                cnt -= 1 ;
            }
            else if (graph[i][idx] == 0) {
                idx -= 1 ;
            }
            else if (graph[i][idx] != 0 && graph[i][idx] == graph[i][idx-1]) {
                graph[i][cnt] = 2 * graph[i][idx] ;
                graph[i][idx-1] = 0 ;
                cnt -= 1 ;
                idx -= 2 ;
            }
            else {
                graph[i][cnt] = graph[i][idx] ;
                idx -= 1 ;
                cnt -= 1 ;
            }
        }
        
        for(int j = cnt ; j > -1 ; j--){
            graph[i][j] = 0 ;
        }
    }
    print() ;
}

void Up() {
    
    int cnt, idx ;
    for(int i = 0 ; i < N ; i++) {
        cnt = N-1 ;
        idx = N-1 ;
        while(true) {
            if (idx == -1) break ;
            if (idx == 0){
            //else if (graph[i][idx] != 0 && idx == 0 ){
            
                graph[cnt][i] = graph[idx][i] ;
                idx -= 1 ;
                cnt -= 1 ;
            }
            else if (graph[idx][i] == 0) {
                idx -= 1 ;
            }
            else if (graph[idx][i] != 0 && graph[idx][i] == graph[idx-1][i]) {
                graph[cnt][i] = 2 * graph[idx][i] ;
                graph[idx-1][i] = 0 ;
                cnt -= 1 ;
                idx -= 2 ;
            }
            else {
                graph[cnt][i] = graph[idx][i] ;
                idx -= 1 ;
                cnt -= 1 ;
            }
        }
        for(int j = cnt ; j > -1 ; j--){
            graph[j][i] = 0 ;
        }
    }
    print() ;
}

void Down() {
    
    int cnt, idx ;
    for(int i = 0 ; i < N ; i++) {
        cnt = 0 ;
        idx = 0 ;
        while(true) {
            if (idx == N) break ;
            //else if (graph[i][idx] != 0 && idx == N-1 ){
            if (idx == N-1 ){
                graph[cnt][i] = graph[idx][i] ;
                idx += 1 ;
                cnt += 1 ;
            }
            else if (graph[idx][i] == 0) {
                idx += 1 ;
            }
            else if (graph[idx][i] != 0 && graph[idx][i] == graph[idx+1][i]) {
                graph[cnt][i] = 2 * graph[idx][i] ;
                graph[idx+1][i] = 0 ;
                cnt += 1 ;
                idx += 2 ;
            }
            else {
                graph[cnt][i] = graph[idx][i] ;
                idx += 1 ;
                cnt += 1 ;
            }
        }
        for(int j = cnt ; j < N ; j++){
            graph[j][i] = 0 ;
        }
    }
    print() ;
}

int find_max() {
    int mx = 0 ;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if (graph[i][j] > mx) mx = graph[i][j] ;
        }
    }
    return mx ;
}

void DFS(int cnt2) {
    
    if (cnt2 == 5) {
        memcpy(graph, ini_graph, sizeof(graph)) ;
        for (int k = 0 ; k < 5 ; k++){
            cout << dfs_lst[k] << " " ;
        }
        cout << endl ;
        for (int t = 0 ; t < 5 ; t++){
            if (dfs_lst[t] == 0) Right() ;
            else if (dfs_lst[t] == 1) Left() ;
            else if (dfs_lst[t] == 2) Up() ;
            else if (dfs_lst[t] == 3) Down() ;
            
        }
        int tmp_result ;
        tmp_result = find_max() ;
        if (result < tmp_result) result = tmp_result ;
        return ;
    }
    
    for (int i = 0 ; i < 4 ; i++){
        dfs_lst[cnt2] = i ;
        DFS(cnt2+1) ;
    }
   
}

int main() {

    cin >> N ;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++){
            cin >> ini_graph[i][j] ;
        }
    }
    
    DFS(0) ;
    cout << result ;
    return 0;
}

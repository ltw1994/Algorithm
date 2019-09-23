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

int find_max() {
    int mx = 0 ;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if (graph[i][j] > mx) mx = graph[i][j] ;
        }
    }
    return mx ;
}

void move(int dir) {
    if (dir == 0){                  //Right
        
    }
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

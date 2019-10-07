//
//  main.cpp
//  5653_줄기세포 배양하기
//
//  Created by 임태완 on 2019. 10. 4..
//  Copyright © 2019년 임태완. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>


struct visited {
    int x ;
    int y ;
} ;

using namespace std ;

const int dx[] = {1, 0, -1, 0} ;
const int dy[] = {0, -1, 0, 1} ;
int graph[401][401] ;
int compare_graph[401][401] ;
vector<visited> v ;
/*
for(int yy = 0 ; yy < N ; yy++) {
    for (int xx = 0 ; xx < M ; xx++ ){
        cout << graph[yy][xx] << " " ;
    }
    cout << endl ;
}
 */

void game(int K, int t) {

    int x, y ,nx, ny, mx ;
    v.clear() ;
    while(K > 0) {
    
        for (int a = 1 ; a < 400 ; a++) {
            for (int b = 1 ; b < 400 ; b++) {
                
                y = a ;
                x = b ;
                mx = 0 ;
            //    cout << endl ;
            //    cout << x << " " << y << endl ;
                if (graph[y][x] == 0) {
                    for (int k = 0 ; k < 4 ; k++) {
                        nx = x + dx[k] ;
                        ny = y + dy[k] ;
                        if (nx < 0 || ny < 0 || nx > 399 || ny > 399) continue ;
                        if (graph[ny][nx] == -1 && mx < compare_graph[ny][nx]) {
          
                            mx = compare_graph[ny][nx] ;
                        }
                    }
                    if (compare_graph[y][x] == 0) compare_graph[y][x] = mx ; 
                    graph[y][x] = mx ;
                }
                else v.push_back({x, y}) ;
            }
        }
        
        for(int p = 0 ; p < v.size() ; p++) {
            x = v[p].x ;
            y = v[p].y ;
            if (graph[y][x] == 1) graph[y][x] -= 2 ;
            else if (graph[y][x] > 1) graph[y][x] -= 1 ;
            else if (graph[y][x] == -1) graph[y][x] -= 1 ;
        }
   
        K -= 1 ;
        
//        for(int yy = 180 ; yy < 220 ; yy++) {
//            for (int xx = 180 ; xx < 220 ; xx++ ){
//                    cout << graph[yy][xx] << " " ;
//                    //result += 1 ;
//                }
//                cout << endl ;
//                //cout << " " << xx << " " << yy << endl ;
//            }
//
//        cout << endl ;
        
    }
    
    int result = 0 ;
    for(int yy = 0 ; yy < 401 ; yy++) {
        for (int xx = 0 ; xx < 401 ; xx++ ){
            if (graph[yy][xx] == -1 || graph[yy][xx] >= 1) {
                result += 1 ;
            }
        }
    }
    cout << "#" << t+1 << " " << result << endl  ;
}




int main() {
    int T ;
    cin >> T ;
    for (int t = 0 ; t < T ; t++) {

        int N, M, K ;
        cin >> N >> M >> K ;
        for (int i = 0 ; i < 401 ; i++) {
            for(int j = 0 ; j < 401 ; j++) {
                compare_graph[i][j] = 0 ;
                graph[i][j] = 0 ;
            }
        }
        for (int i = 180 ; i < 180+N ; i++) {
            for  (int j = 180 ; j < 180+M ; j++) {
                cin >> graph[i][j] ;
                compare_graph[i][j] = graph[i][j] ;
                //if (graph[i][j] != 0) mxv.push_back({j, i, graph[i][j]}) ;
            }
        }
        game(K, t) ;
    }
}

/*
#include <iostream>
#include <cstring>
#include <string.h>

using namespace std ;

const int dx[] = {1, 0, -1, 0} ;
const int dy[] = {0, -1, 0, 1} ;
int graph[401][401] ;
int compare_graph[401][401] ;

void game(int K, int t) {
    
    int x, y ,nx, ny, mx ;
    while(K > 0) {
        int visited[401][401] ;
        for (int i = 0 ; i < 401 ; i++) {
            for(int j = 0 ; j < 401 ; j++) {
                visited[i][j] = 0 ;
            }
        }
        
        for (int a = 1 ; a < 400 ; a++) {
            for (int b = 1 ; b < 400 ; b++) {
                
                y = a ;
                x = b ;
                mx = 0 ;
                //    cout << endl ;
                //    cout << x << " " << y << endl ;
                if (graph[y][x] == 0) {
                    visited[y][x] = 1 ;
                    for (int k = 0 ; k < 4 ; k++) {
                        nx = x + dx[k] ;
                        ny = y + dy[k] ;
                        if (nx < 0 || ny < 0 || nx > 399 || ny > 399) continue ;
                        if (graph[ny][nx] == -1 && mx < compare_graph[ny][nx]) {
                            
                            mx = compare_graph[ny][nx] ;
                        }
                    }
                    if (compare_graph[y][x] == 0) compare_graph[y][x] = mx ;
                    graph[y][x] = mx ;
                }
            }
        }
        for (int a = 0 ; a < 401 ; a++) {
            for (int b = 0 ; b < 401 ; b++) {
                if (visited[a][b] == 1) continue ;
                y = a ;
                x = b ;
                if (graph[y][x] == 1) graph[y][x] -= 2 ;
                else if (graph[y][x] > 1) graph[y][x] -= 1 ;
                else if (graph[y][x] == -1) graph[y][x] -= 1 ;
            }
        }
        K -= 1 ;
        
        //        for(int yy = 180 ; yy < 220 ; yy++) {
        //            for (int xx = 180 ; xx < 220 ; xx++ ){
        //                    cout << graph[yy][xx] << " " ;
        //                    //result += 1 ;
        //                }
        //                cout << endl ;
        //                //cout << " " << xx << " " << yy << endl ;
        //            }
        //
        //        cout << endl ;
        
    }
    
    int result = 0 ;
    for(int yy = 0 ; yy < 401 ; yy++) {
        for (int xx = 0 ; xx < 401 ; xx++ ){
            if (graph[yy][xx] == -1 || graph[yy][xx] >= 1) {
                result += 1 ;
            }
        }
    }
    cout << "#" << t+1 << " " << result << endl  ;
}




int main() {
    int T ;
    cin >> T ;
    for (int t = 0 ; t < T ; t++) {
        int N, M, K ;
        cin >> N >> M >> K ;
        for (int i = 0 ; i < 401 ; i++) {
            for(int j = 0 ; j < 401 ; j++) {
                graph[i][j] = 0 ;
                compare_graph[i][j] = 0 ;
            }
        }
        for (int i = 180 ; i < 180+N ; i++) {
            for  (int j = 180 ; j < 180+M ; j++) {
                cin >> graph[i][j] ;
                compare_graph[i][j] = graph[i][j] ;
            }
        }
        game(K, t) ;
    }
}

*/

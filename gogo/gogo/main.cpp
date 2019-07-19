#include <iostream>
#include <math.h>
#include <queue>

using namespace std;
queue <int> q ;

int V, E ;
int graph[20002][20002] ;
int dis[20002] ;
int real_distance[20002] ;
bool visited[20002] ;
int start ;
int now ;


int main(){
    int u, v, w;
    cin >> V >> E >> start ;
    
    for(int i = 1 ; i < V+1 ; i++){
        dis[i] = 999999;
    }
    
    for(int i = 0 ; i < E ; i++){
        cin >> u >> v >> w ;
        graph[u][v] = w ;
    }
    q.push(start) ;
    real_distance[start] = 0 ;
    visited[start] = true ;
    int count = 1 ;
    while(q.size() > 0){
        
        int tmp = 999999 ;
        int tmp_node = 0 ;
        bool isokay = false ;
        now = q.back() ;
        q.pop() ;
        cout << "혹시 루프중?" << count << "" << now << "하는중 ㅋ " << endl ;
        for(int i = 1 ; i < V+1 ; i++){
            if (graph[now][i] != 0 && visited[i] == false){
                real_distance[i] += graph[now][i] ;
            }
        }
        for(int i = 1 ; i < V+1 ; i++){
            if (real_distance[i] >= real_distance[now] + graph[now][i] && tmp > real_distance[now] + real_distance[i] && visited[i] == false && graph[now][i] != 0){
                tmp = real_distance[now] + real_distance[i] ;
                tmp_node = i ;
                isokay = true ;
            }
            
        }
        if (isokay == true){
            visited[tmp_node] = true ;
            q.push(tmp_node) ;
            
        }
        count += 1 ;
        for(int k = 1 ; k < V+1 ; k++){
            cout << real_distance[k] << " "  ;
        }
    }
    for(int i = 1 ; i < V+1 ; i++){
        if (i != start){
            cout << i << "까지 도달하는데 걸리는 거리는" << real_distance[i] << endl ;
        }
    }
    
}

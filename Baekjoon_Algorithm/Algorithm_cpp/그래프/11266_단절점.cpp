#include <iostream>
#include <math.h>

using namespace std;

int graph[10003][10003] ;
bool visited_node[10001] ;
int order[10001] ;
int num = 1 ;
int V, E ;
int low[10003] ;
int result[10003] ;
bool finish[10003]
void DFS(int start, bool root){
    int tmp = 0;
    order[start] = num ;
    num += 1 ;
    if (low[start] == 0)
        low[start] = order[start] ;
    visited_node[start] = true ;
    
    for(int j = 0 ; j < E ; j++){
        if (graph[start][j] == 1 and visited_node[j] == false){
            DFS(j, false) ;
        }
    }
    finish[start] = true ;
    for(int j = 0 ; j < E ; j++){
        if(low[start] < low[j])
            result[start] = 1 ;
    }
}




int main(){

    int A, B ;
    cin >> V >> E ;
    for(int i = 0 ; i < E ; i++){
        cin >> A >> B ;
        graph[A][B] = 1 ;
        graph[B][A] = 1 ;
    }
    

    for(int i = 1 ; i < V+1 ; i++){
        for(int k = 1 ; k < V+1 ; k++){
            order[k] = 1;
            visited_node[k] = false ;
            finish[k] = false ;
        }
        num = 1 ;
        DFS(i, true) ;
        cout << i << "에서는" << " " ;
        for(int w = 1 ; w < V+1 ; w++){
            cout << result[w] << " " ;
        }
        cout << endl ;
    }
    for(int i = 1 ; i < V+1 ; i++){
        if(result[i] == 1){
            cout << i << " ";
        }
    }
    
}


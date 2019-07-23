#include <iostream>
#include <math.h>
#include <queue>

using namespace std;
queue <int> q ;

int d[503][503] ;
int mx = 0 ;
int start = 9 ;

int max(int a, int b){
    return a > b? a : b ;
}
int main(){
    
    int n ;
    
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <= i ; j++){
            cin >> d[i][j] ;
        }
    }
    
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j <= i ; j++){
            if(j == 0) d[i][j] += d[i-1][j] ;
            else if (j == i) d[i][j] += d[i-1][j-1] ;
            else d[i][j] += max(d[i-1][j-1], d[i-1][j]) ;
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        mx = max(mx, d[n-1][i]) ;
    }
    
    cout << mx ;
    
}


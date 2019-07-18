
#include <iostream>
using namespace std;
int N ;
int tmp[3] ;
int max_arr[2][3] ;
int min_arr[2][3] ;


int main() {
    
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    cin >> N ;
    
    for(int i = 1 ; i < N+1 ; i++){
        
        cin >> tmp[0] >> tmp[1] >> tmp[2] ;
        
        max_arr[1][0] = max(max_arr[0][0],max_arr[0][1]) + tmp[0] ;
        max_arr[1][1] = max(max(max_arr[0][0],max_arr[0][1]),max_arr[0][2]) + tmp[1] ;
        max_arr[1][2] = max(max_arr[0][1],max_arr[0][2]) + tmp[2] ;
    
        min_arr[1][0] = min(min_arr[0][0],min_arr[0][1]) + tmp[0] ;
        min_arr[1][1] = min(min(min_arr[0][0],min_arr[0][1]),min_arr[0][2]) + tmp[1] ;
        min_arr[1][2] = min(min_arr[0][1],min_arr[0][2]) + tmp[2] ;

        for(int j = 0 ; j < 3 ; j++){
            max_arr[0][j] = max_arr[1][j] ;
            min_arr[0][j] = min_arr[1][j] ; 
            
        }
    }

    
    cout << max(max(max_arr[1][0], max_arr[1][1]), max_arr[1][2]) << " " << min(min(min_arr[1][0], min_arr[1][1]), min_arr[1][2]);
    
}


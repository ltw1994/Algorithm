#include <iostream>
using namespace std;
long N ;
long long runner[500001] ;
long long result[500001] ;
long long current_runner = 0 ;
long long idx = 0 ;
long long num = 0 ;

int main() {
    cin >> N ;
    
    for(int i = 0 ; i < N ; i++)
        cin >> runner[i] ;
    for(int i = 0 ; i < N ; i++){
        idx = 0 ; 
        current_runner = runner[i] ;
        for(int j = 0 ; j < i ; j++){
            if (current_runner > runner[j])
                idx += 1 ;
        }
        num = i + 1 - idx ;
        result[i] = num ;
    }
    
    for(int i = 0 ; i < N ; i++)
        cout << result[i] << endl ;
    
}


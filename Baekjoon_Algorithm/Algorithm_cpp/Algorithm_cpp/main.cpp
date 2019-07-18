#include <iostream>
#include <math.h>

using namespace std;

long long tree[2000001] ;
long long tmp[3] ;
long long bin = 0 ;
long long tmp_n = 0 ;
long long mid = 0 ;
int main(){
    
    long n, m, k ;
    
    cin >> n >> m >> k ;
    tmp_n = n;
    while (tmp_n > 0){
        tmp_n /= 2 ;
        bin += 1 ;
    }
    mid = pow(2,bin) ;
    for(long long i=0 ; i < n ; i++){
        cin >> tree[mid+i] ;
    }
    
    for(long long j = mid-1 ; j >= 0 ; j--) {
        tree[j] = tree[2*j] + tree[2*j+1] ;
    }
    
    for(long long i = 0 ; i < 2 * mid ; i++)
        cout << i << " " << tree[i] << endl ;
    
}

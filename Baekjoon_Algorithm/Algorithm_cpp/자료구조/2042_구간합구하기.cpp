#include <iostream>
#include <math.h>

using namespace std;

long long tree[4000005] ;
long long bin = 0 ;
int tmp_n = 0 ;
int mid = 0 ;

void change_value(int b, long long c){
    
    //  cout << "이거 하는 중" << endl ;
    int idx = 0 ;
    long long value = 0 ;
    idx = mid + b - 1;
    value = c - tree[idx] ;
    while(idx > 0){
        
        tree[idx] += value ;
        idx /= 2 ;
        
    }
    
}

long long sum_value(int b, long long c){
    
    //cout << "이것도 하는 중 " << endl ;
    long long sum = 0 ;
    int lef = mid + b - 1 ;
    int rig = mid + (int)c - 1;
    while(lef <= rig){
        //     cout << "혹시 무한루프?" << endl ;
        if (lef % 2 != 0){
            sum += tree[lef] ;
            lef += 1 ;
        }
        if (rig % 2 == 0){
            sum += tree[rig] ;
            rig -= 1 ;
        }
        
        if(lef == rig) break;
        lef /= 2;
        rig /= 2;
        
    }
    
    return sum ;
}


int main(){
    
    long long n, m, k ;
    long long total =  0 ;
    int a, b ;
    long long c;
    long long result = 0 ;
    
    cin >> n >> m >> k ;
    total = m + k ;
    tmp_n = n;
    while (tmp_n > 0){
        tmp_n /= 2 ;
        bin += 1 ;
    }
    mid = pow(2,bin) ;
    for(int i=0 ; i < n ; i++){
        cin >> tree[mid+i] ;
    }
    
    for(int j = mid-1 ; j > 0 ; j--) {
        tree[j] = tree[2*j] + tree[2*j+1] ;
    }
    
    //for(long long i = 0 ; i < 2 * mid ; i++)
    //    cout << i << " " << tree[i] << endl ;
    
    for(long long epoch = 0 ; epoch < total ; epoch++){
        cin >> a >> b >> c ;
        if(a==1)
            change_value(b, c);
        else{
            result = sum_value(b, c) ;
            cout << result << endl;
        }
        
    }
    
}

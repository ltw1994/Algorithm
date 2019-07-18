#include <iostream>
using namespace std;
long N ;
long S ;
long arr[100001] ;
int lef = 0 ;
int rig = 0 ;
int no = 92911937 ;


int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> S;
    
    for(int i = 0 ; i < N ; i++)
        cin >> arr[i];
    
    int result = no;
    
    long num = arr[0] ;
    while(rig < N && lef <= rig){
        //  cout << num << endl ;

        if (num < S){
            num += arr[++rig] ;
        }
            
        else if (num == S){
            result = min(result,rig - lef + 1) ;
            num += arr[++rig] ;
        }
            
        else if (num > S){
            result = min(result,rig - lef + 1) ;
            num -= arr[lef++] ;
        }
        }
        
    if (result == no)
        cout << 0 ;
    else
        cout << result ; 
    }
    
    


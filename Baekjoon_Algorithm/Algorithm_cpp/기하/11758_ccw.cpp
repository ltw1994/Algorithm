#include <iostream>
#include <vector>
#include <queue>
#include <stack>


using namespace std;


int arr[1000001] ;
vector<int> vt ;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int S ;
    int ans ;
    
    int x1, x2, x3, y1, y2, y3 ;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ;
    S = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (S > 0) {
        ans = 1;
    }
    else if (S < 0) {
        ans = -1;
    }
    else {
        ans = 0;
    }
    cout << ans ;
    
}


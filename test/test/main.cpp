#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

double CCW(double x1, double y1, double x2, double y2, double x3, double y3){
    double ret = x1 * y2 + x2 * y3 + x3 * y1 - (y1 * x2 + y2 * x3 + y3 * x1) ;

    return ret ;
}

queue <int> q ;
long long x[100001], y[100001] ;

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int N ;
    cin >> N ;
    for(int i = 0 ; i < N ; i++){
        cin >> x[i] >> y[i] ;
    }
}
        

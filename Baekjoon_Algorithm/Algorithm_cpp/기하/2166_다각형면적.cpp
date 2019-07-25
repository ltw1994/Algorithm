#include <iostream>
#include <vector>
#include <queue>
#include <stack>


using namespace std;


double x[3] ;
double y[3] ;
vector<int> vt ;


double CCW(double x1, double y1, double x2, double y2, double x3, double y3){
    double ret = x1 * y2 + x2 * y3 + x3 * y1 - (y1 * x2 + y2 * x3 + y3 * x1) ;
  //  printf(".1%lf", ret) ;
   // printf("\n") ;
    return ret ;
}


int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double sum = 0 ;
    int N ;
    cin >> N ;
    cin >> x[2] >> y[2] >> x[0] >> y[0] ;
    int i = 1;
    int cnt = 2 ;
    while(true){
        if (cnt >= N)
            break ;
        cin >> x[i] >> y[i] ;
        sum += CCW(x[2], y[2], x[(i+1) % 2], y[(i+1) % 2], x[i], y[i]) /2.0 ;
        //printf("여기") ;
        //printf("%.1lf", sum) ;
        //printf("\n") ;
        i = (i+1) % 2 ;
        cnt++ ;
    }
    
    if (sum > 0) printf("%.1lf", sum) ; else printf("%.1lf", sum * -1) ;
}


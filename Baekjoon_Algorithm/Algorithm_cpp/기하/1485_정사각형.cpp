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
long long x[4], y[4], s[6];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i, j, k, tc;
    
    cin >> tc;
    while (tc--)
    {
        k = 0;
        for (i = 0; i < 4; i++)
            scanf("%lld %lld", &x[i], &y[i]);
        
        for (i = 0; i < 4; i++)
            for (j = i + 1; j < 4; j++)
            {
                s[k] = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
                k++;
            }
        
        sort(s, s + 6);
        if(s[0] == s[1] && s[1] == s[2] && s[2] == s[3] && s[4] == s[5]) :
            cout << 1 ;
        else
            cout << 0;
    }
}


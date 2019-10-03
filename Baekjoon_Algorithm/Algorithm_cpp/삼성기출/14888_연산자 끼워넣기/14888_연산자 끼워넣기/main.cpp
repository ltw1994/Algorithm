//
//  main.cpp
//  14888_연산자 끼워넣기
//
//  Created by 임태완 on 2019. 10. 3..
//  Copyright © 2019년 임태완. All rights reserved.
//

#include <iostream>
using namespace std ;

int nums[12] ;
int products[12] ;
int a, m, p, d ;
int maxResult = -1000000000;
int minResult = 1000000000;


void DFS(int add, int minus, int product, int devide, int cnt, int N, int idx){
    if (cnt == N-1) {
        if (idx > maxResult) {
            maxResult = idx ;
        }
        if (idx < minResult) {
            minResult = idx ;
        }
        return ;
    }
    
    if (add < a) DFS(add + 1, minus, product, devide, cnt + 1, N, idx + nums[cnt+1]) ;
    if (minus < m) DFS(add, minus + 1, product, devide, cnt + 1, N, idx - nums[cnt+1]) ;
    if (product < p) DFS(add, minus, product + 1, devide, cnt + 1, N , idx * nums[cnt+1]) ;
    if (devide < d) DFS(add, minus, product, devide + 1 , cnt + 1, N, idx / nums[cnt+1]) ;
}
int main() {
    
    int N ;
    cin >> N ;
    for (int i = 0 ; i < N ; i++) {
        cin >> nums[i] ;
    }
    cin >> a >> m >> p >> d ;
    DFS(0, 0, 0, 0, 0, N, nums[0]) ;
    cout << maxResult << endl ;
    cout << minResult ;
    
    return 0;
}

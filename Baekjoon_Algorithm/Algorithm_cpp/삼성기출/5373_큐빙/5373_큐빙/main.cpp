//
//  main.cpp
//  5373_큐빙
//
//  Created by 임태완 on 2019. 9. 2..
//  Copyright © 2019년 임태완. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std ;
vector<pair<char, char>> V ;
vector<char> cube[6] ;
int epoch ;
int T ;

void reset() {
    V.clear() ;
    for (int i = 0 ; i < 6 ; i++) {
        cube[i].clear() ;
    }
    for (int i = 0 ; i < 9 ; i++) {
        cube[0].push_back('w') ;
        cube[1].push_back('y') ;
        cube[2].push_back('r') ;
        cube[3].push_back('o') ;
        cube[4].push_back('g') ;
        cube[5].push_back('b') ;
    }
}

void front_turn(char d, char p) {
    int tmp1, idx1, tmp2 ;
    
    if (p == 'U') idx1 = 0 ;
    if (p == 'D') idx1 = 1 ;
    if (p == 'F') idx1 = 2 ;
    if (p == 'B') idx1 = 3 ;
    if (p == 'L') idx1 = 4 ;
    if (p == 'R') idx1 = 5 ;
    
    //cout << idx1 << endl ;
    
    if (d == '+') {
        tmp1 = cube[idx1].at(0) ;
        tmp2 = cube[idx1].at(3) ;
        cube[idx1].at(0) = cube[idx1].at(6) ;
        cube[idx1].at(3) = cube[idx1].at(7) ;
        cube[idx1].at(6) = cube[idx1].at(8) ;
        cube[idx1].at(7) = cube[idx1].at(5) ;
        cube[idx1].at(8) = cube[idx1].at(2) ;
        cube[idx1].at(5) = cube[idx1].at(1) ;
        cube[idx1].at(2) = tmp1 ;
        cube[idx1].at(1) = tmp2 ;
    }
        
    if (d == '-') {
        tmp1 = cube[idx1].at(0) ;
        tmp2 = cube[idx1].at(1) ;
        cube[idx1].at(0) = cube[idx1].at(2) ;
        cube[idx1].at(1) = cube[idx1].at(5) ;
        cube[idx1].at(2) = cube[idx1].at(8) ;
        cube[idx1].at(5) = cube[idx1].at(7) ;
        cube[idx1].at(8) = cube[idx1].at(6) ;
        cube[idx1].at(7) = cube[idx1].at(3) ;
        cube[idx1].at(6) = tmp1 ;
        cube[idx1].at(3) = tmp2 ;
    }
}

void turn(char p, char d) {
    int tmp1, tmp2, tmp3 ;

    
    
    front_turn(d, p) ;
    if (p == 'U') {
        if (d == '+') {
            
            tmp1 = cube[5].at(0);
            tmp2 = cube[5].at(1);
            tmp3 = cube[5].at(2);
            
            cube[5].at(0) = cube[3].at(0);
            cube[5].at(1) = cube[3].at(1);
            cube[5].at(2) = cube[3].at(2);
            
            cube[3].at(0) = cube[4].at(0);
            cube[3].at(1) = cube[4].at(1);
            cube[3].at(2) = cube[4].at(2);
            
            cube[4].at(0) = cube[2].at(0);
            cube[4].at(1) = cube[2].at(1);
            cube[4].at(2) = cube[2].at(2);
            
            cube[2].at(0) = tmp1;
            cube[2].at(1) = tmp2;
            cube[2].at(2) = tmp3;
            
            
            }
    
        if (d == '-') {
            
            tmp1 = cube[5].at(0);
            tmp2 = cube[5].at(1);
            tmp3 = cube[5].at(2);
            
            cube[5].at(0) = cube[2].at(0);
            cube[5].at(1) = cube[2].at(1);
            cube[5].at(2) = cube[2].at(2);
            
            cube[2].at(0) = cube[4].at(0);
            cube[2].at(1) = cube[4].at(1);
            cube[2].at(2) = cube[4].at(2);
            
            cube[4].at(0) = cube[3].at(0);
            cube[4].at(1) = cube[3].at(1);
            cube[4].at(2) = cube[3].at(2);
            
            cube[3].at(0) = tmp1;
            cube[3].at(1) = tmp2;
            cube[3].at(2) = tmp3;
        }
    }
    
    if (p == 'D') {
        if (d == '+') {
            
            tmp1 = cube[2].at(6);
            tmp2 = cube[2].at(7);
            tmp3 = cube[2].at(8);
            
            cube[2].at(6) = cube[4].at(6);
            cube[2].at(7) = cube[4].at(7);
            cube[2].at(8) = cube[4].at(8);
            
            cube[4].at(6) = cube[3].at(6);
            cube[4].at(7) = cube[3].at(7);
            cube[4].at(8) = cube[3].at(8);
            
            cube[3].at(6) = cube[5].at(6);
            cube[3].at(7) = cube[5].at(7);
            cube[3].at(8) = cube[5].at(8);
            
            cube[5].at(6) = tmp1;
            cube[5].at(7) = tmp2;
            cube[5].at(8) = tmp3;
            
            
        }
        
        if (d == '-') {
            
            tmp1 = cube[2].at(6);
            tmp2 = cube[2].at(7);
            tmp3 = cube[2].at(8);
            
            cube[2].at(6) = cube[5].at(6);
            cube[2].at(7) = cube[5].at(7);
            cube[2].at(8) = cube[5].at(8);
            
            cube[5].at(6) = cube[3].at(6);
            cube[5].at(7) = cube[3].at(7);
            cube[5].at(8) = cube[3].at(8);
            
            cube[3].at(6) = cube[4].at(6);
            cube[3].at(7) = cube[4].at(7);
            cube[3].at(8) = cube[4].at(8);
            
            cube[4].at(6) = tmp1;
            cube[4].at(7) = tmp2;
            cube[4].at(8) = tmp3;
        }
    }
    
    if (p == 'F') {
        if (d == '+') {
            
            tmp1 = cube[0].at(6);
            tmp2 = cube[0].at(7);
            tmp3 = cube[0].at(8);
            
            cube[0].at(6) = cube[4].at(8);
            cube[0].at(7) = cube[4].at(5);
            cube[0].at(8) = cube[4].at(2);
            
            cube[4].at(8) = cube[1].at(2);
            cube[4].at(5) = cube[1].at(1);
            cube[4].at(2) = cube[1].at(0);
            
            cube[1].at(2) = cube[5].at(0);
            cube[1].at(1) = cube[5].at(3);
            cube[1].at(0) = cube[5].at(6);
            
            cube[5].at(0) = tmp1;
            cube[5].at(3) = tmp2;
            cube[5].at(6) = tmp3;
            
            
        }
        
        if (d == '-') {
            
            tmp1 = cube[0].at(6);
            tmp2 = cube[0].at(7);
            tmp3 = cube[0].at(8);
            
            cube[0].at(6) = cube[5].at(0);
            cube[0].at(7) = cube[5].at(3);
            cube[0].at(8) = cube[5].at(6);
            
            cube[5].at(0) = cube[1].at(2);
            cube[5].at(3) = cube[1].at(1);
            cube[5].at(6) = cube[1].at(0);
            
            cube[1].at(2) = cube[4].at(8);
            cube[1].at(1) = cube[4].at(5);
            cube[1].at(0) = cube[4].at(2);
            
            cube[4].at(8) = tmp1;
            cube[4].at(5) = tmp2;
            cube[4].at(2) = tmp3;
        }
    }
    
    if (p == 'B') {
        if (d == '+') {
            
            tmp1 = cube[0].at(0);
            tmp2 = cube[0].at(1);
            tmp3 = cube[0].at(2);
            
            cube[0].at(0) = cube[5].at(2);
            cube[0].at(1) = cube[5].at(5);
            cube[0].at(2) = cube[5].at(8);
            
            cube[5].at(2) = cube[1].at(8);
            cube[5].at(5) = cube[1].at(7);
            cube[5].at(8) = cube[1].at(6);
            
            cube[1].at(8) = cube[4].at(6);
            cube[1].at(7) = cube[4].at(3);
            cube[1].at(6) = cube[4].at(0);
            
            cube[4].at(6) = tmp1;
            cube[4].at(3) = tmp2;
            cube[4].at(0) = tmp3;
            
            
        }
        
        if (d == '-') {
            
            tmp1 = cube[0].at(0);
            tmp2 = cube[0].at(1);
            tmp3 = cube[0].at(2);
            
            cube[0].at(0) = cube[4].at(6);
            cube[0].at(1) = cube[4].at(3);
            cube[0].at(2) = cube[4].at(0);
            
            cube[4].at(6) = cube[1].at(8);
            cube[4].at(3) = cube[1].at(7);
            cube[4].at(0) = cube[1].at(6);
            
            cube[1].at(8) = cube[5].at(2);
            cube[1].at(7) = cube[5].at(5);
            cube[1].at(6) = cube[5].at(8);
            
            cube[5].at(2) = tmp1;
            cube[5].at(5) = tmp2;
            cube[5].at(8) = tmp3;
        }
    }
    
    if (p == 'L') {
        if (d == '+') {
            
            tmp1 = cube[2].at(0);
            tmp2 = cube[2].at(3);
            tmp3 = cube[2].at(6);
            
            cube[2].at(0) = cube[0].at(0);
            cube[2].at(3) = cube[0].at(3);
            cube[2].at(6) = cube[0].at(6);
        
            cube[0].at(0) = cube[3].at(8);
            cube[0].at(3) = cube[3].at(5);
            cube[0].at(6) = cube[3].at(2);
            
            cube[3].at(8) = cube[1].at(0);
            cube[3].at(5) = cube[1].at(3);
            cube[3].at(2) = cube[1].at(6);
            
            cube[1].at(0) = tmp1;
            cube[1].at(3) = tmp2;
            cube[1].at(6) = tmp3;
            
            
        }
        
        if (d == '-') {
            
            tmp1 = cube[2].at(0);
            tmp2 = cube[2].at(3);
            tmp3 = cube[2].at(6);
            
            cube[2].at(0) = cube[1].at(0);
            cube[2].at(3) = cube[1].at(3);
            cube[2].at(6) = cube[1].at(6);
            
            cube[1].at(0) = cube[3].at(8);
            cube[1].at(3) = cube[3].at(5);
            cube[1].at(6) = cube[3].at(2);
            
            cube[3].at(8) = cube[0].at(0);
            cube[3].at(5) = cube[0].at(3);
            cube[3].at(2) = cube[0].at(6);
            
            cube[0].at(0) = tmp1;
            cube[0].at(3) = tmp2;
            cube[0].at(6) = tmp3;
        }
    }
    
    if (p == 'R') {
        if (d == '+') {
            
            tmp1 = cube[2].at(2);
            tmp2 = cube[2].at(5);
            tmp3 = cube[2].at(8);
            
            cube[2].at(2) = cube[1].at(2);
            cube[2].at(5) = cube[1].at(5);
            cube[2].at(8) = cube[1].at(8);
            
            cube[1].at(2) = cube[3].at(6);
            cube[1].at(5) = cube[3].at(3);
            cube[1].at(8) = cube[3].at(0);
            
            cube[3].at(6) = cube[0].at(2);
            cube[3].at(3) = cube[0].at(5);
            cube[3].at(0) = cube[0].at(8);
            
            cube[0].at(2) = tmp1;
            cube[0].at(5) = tmp2;
            cube[0].at(8) = tmp3;
            
            
        }
        
        if (d == '-') {
            
            tmp1 = cube[2].at(2);
            tmp2 = cube[2].at(5);
            tmp3 = cube[2].at(8);
            
            cube[2].at(2) = cube[0].at(2);
            cube[2].at(5) = cube[0].at(5);
            cube[2].at(8) = cube[0].at(8);
            
            cube[0].at(2) = cube[3].at(6);
            cube[0].at(5) = cube[3].at(3);
            cube[0].at(8) = cube[3].at(0);
            
            cube[3].at(6) = cube[1].at(2);
            cube[3].at(3) = cube[1].at(5);
            cube[3].at(0) = cube[1].at(8);
            
            cube[1].at(2) = tmp1;
            cube[1].at(5) = tmp2;
            cube[1].at(8) = tmp3;
        }
    }
}


int main() {
    cin >> epoch ;
    for (int e = 0 ; e < epoch ; e++) {
        reset() ;
        cin >> T ;
        for (int t = 0 ; t < T ; t++){
            string go ;
            cin >> go ;
            char place, dir ;
            place = go[0] ;
            dir = go[1] ;
            //V.push_back(make_pair(place, dir)) ;
            turn(place, dir) ;
            
         //   cout << t << " " << endl ;
//            for (int o = 0 ; o < 9 ; o++) {
//                cout << cube[0].at(o)  ;
//                if (o % 3 == 2){
//                    cout << endl ;
//                }
//            }
//            cout << endl ;
        }
        for (int o = 0 ; o < 9 ; o++) {
            cout << cube[0].at(o) ;
            if (o % 3 == 2){
                cout << endl ;
            }
        }
    }
    return 0;
}

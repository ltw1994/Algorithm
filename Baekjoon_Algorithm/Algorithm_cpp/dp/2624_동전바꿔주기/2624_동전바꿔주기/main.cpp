//
//  main.cpp
//  2624_동전바꿔주기
//
//  Created by 임태완 on 2019. 10. 13..
//  Copyright © 2019년 임태완. All rights reserved.
//

#include <iostream>

using namespace std ;

struct StackArray {
    private :
    int *Stack ;
    int Size ;
    int Top ;
    public :
    void init(int aSize) {
        Size = aSize ;
        Stack = (int *)malloc(Size*sizeof(int)) ;
        Top = -1 ;
    }
    bool push(int item) {
        if(Top >= Size) return false ;
        else {
            cout << " " << Top ;
            Top++ ;
            Stack[Top] = item ;
            return true ;
        }
    }
    int pop() {
        if(Top >= 0) return Stack[Top--] ;
        else return -1 ;
    }
    int front() {
        if(Top >= 0) return Stack[Top] ;
        else return -1 ;
    }
    int back() {
        if(Top >= 0) return Stack[0] ;
        else return -1;
    }
    bool empty() {
        if(Top == -1 ) return true ;
        else if (Top >= 0) return false ;
        return false ;
    }
    void print() {
        for(int i = 0 ; i < Size ; i++) {
            cout << " 시작 " <<  Stack[i] << " " << Top ;
        }
        cout << endl ;
    }
    
};
int main() {
    StackArray s ;
    s.init(5) ;
    s.push(0) ;
    s.push(1) ;
    s.push(3) ;
    s.push(7) ; 
    s.pop() ;
    s.print() ;
    
    
    return 0;
}

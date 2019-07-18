#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

long long gwal[100] ;
long long tmp[3] ;
int result = 0 ;
int idx = 0 ;
char c ;
int k = 1 ;
bool add = true ;

int main(){
    
    stack<char> s ;
    
    string str ;
    
    cin >> str ;
    
    for(int i = 0 ; i < str.length() ; i++){
        gwal[i] = str.at(i) ;
    }
    
    while(idx < str.length()){
        c = gwal[idx] ;
        //cout << c << endl ;
        if (c != '[' && c != '(' && c != ')' && c!= ']'){
            result = 0 ;
            break;
        }
        
        else if (c == ')' && s.empty()){
            result = 0 ;
            break;
        }
        else if (c == ']' && s.empty()){
            result = 0 ;
            break ;
        }
            
        else if (c == '['){
            k *= 3 ;
            s.push(c) ;
            add = true ;
        }
        else if (c == '('){
            k  *= 2 ;
            s.push(c) ;
            add = true ;
        }
        else if (c == ']' && s.top() == '['){
            if(add == true){
                result += k ;
                k /= 3 ;
                s.pop() ;
                add = false ;
            }
            else{
                k /= 3 ;
                s.pop() ;
            }
        }
        else if (c == ')' && s.top() == '('){
            if(add == true){
              //  cout << k << endl ;
                result += k ;
                k /= 2 ;
                s.pop() ;
                add = false ;
            }
            else{
                k /= 2 ;
                s.pop() ;
            }
        }
        
        else if (c == ')' && s.top() != '(' ){
            result = 0 ;
            break ;
        }
        
        else if(c == ']' && s.top() != '['){
            result = 0 ;
            break;
        }
        
        idx += 1 ;
    }
    if (!s.empty())
        result = 0 ;
    
    cout << result ;
    
    
}



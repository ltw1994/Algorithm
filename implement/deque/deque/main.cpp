#include <iostream>
using namespace std;
const int MAX = 10;
struct Deque{
    int data[MAX];
    int i = 0, j = 0;
    
    bool empty() {
        return i == j;
    }
    void push_front(int x) {
        data[i] = x;
        i = (i + 1) % MAX;
        
    }
    void push_back(int x) {
        j = (j + 1) % MAX;
        data[j] = x;
    }
    void pop_front() {
        i = (i + 1) % MAX;
    }
    void pop_back() {
        j = (j - 1 + MAX) % MAX;
    }
    int front() {
        return data[(i + 1) % MAX];
    }
    int back() {
        return data[j];
    }
    int size() {
        return (j - i + MAX) % MAX;
    }
    
};

Deque dq;
int main() {
    for (int i = 1; i <= 3; i++) {
        dq.push_front(i);
    }
    for (int i = 4; i <= 6; i++) {
        dq.push_back(i);
    }
    dq.push_back(3) ;
    for(int i = 0 ; i < 7 ; i++) {
        cout << dq.data[i];
    }
    return 0;
}

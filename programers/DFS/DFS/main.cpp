#include <string>
#include <vector>
#include <iostream>

using namespace std;

void DFS(int current, int cnt) {
    cout << current << " " << cnt << endl ;
    if (cnt == numbers.size()) {
        if (current == target) {
            result += 1 ;
        }
        cnt -= 1 ;
        return ;
    }
    
    current += numbers[cnt] ;
    cnt += 1 ;
    DFS(current, cnt) ;
    current -= numbers[cnt] ;
    current -= numbers[cnt] ;
    cnt += 1 ;
    DFS(current, cnt) ;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    return answer;
}

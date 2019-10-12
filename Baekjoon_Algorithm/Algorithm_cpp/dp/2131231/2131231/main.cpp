#include <string>
#include <vector>
#include <iostream>
using namespace std;

//void print(vector<int> odo) {
//    for(int i = 0 ; i < odo.size() ; i++ ){
//        cout << odo[i] ;
//    }
//    cout << endl ;
//    return ;
//}
//
//int find_car(int car1 , int car2, vector<string> plates) {
//    int cnt = 0 ;
//    char c1 ;
//    char c2 ;
//    while(plates[car1][cnt] == plates[car2][cnt]) {
//        cnt += 1 ;
//    }
//    c1 = plates[car1][cnt] ;
//    c2 = plates[car2][cnt] ;
//    if (c1 > c2) return car2 ;
//    else return car1 ;
//}

string solution(int n, vector<string> plates, vector<int> odo, int k, vector<int> drives) {
    
    string answer = "";
    int cnt = 0 ;
    int temp = odo[9] ;
    int tempCar = 0 ;
    while (cnt < k+1) {
        //print(odo) ;
        temp = odo[0] ;
        tempCar = 0 ;
        for(int i = 0 ; i < odo.size() ; i++) {
            if (temp > odo[i]){
                temp = odo[i] ;
                tempCar = i ;
            }
            else if (temp == odo[i]) {
                int cnt2 = 0 ;
                char c1, c2 ;
                while(plates[tempCar][cnt] == plates[i][cnt]) {
                    cnt2 += 1 ;
                }
                c1 = plates[tempCar][cnt] ;
                c2 = plates[i][cnt] ;
                if (c1 > c2) tempCar = i ;
            }
        }
        odo[tempCar] += drives[cnt] ;
        cnt += 1 ;
    }
    temp = odo[0] ;
    tempCar = 0 ;
    for(int i = 0 ; i < odo.size() ; i++) {
        if (temp > odo[i]){
            temp = odo[i] ;
            tempCar = i ;
        }
        else if (temp == odo[i]) {
            int cnt2 = 0 ;
            char c1, c2 ;
            while(plates[tempCar][cnt] == plates[i][cnt]) {
                cnt2 += 1 ;
            }
            c1 = plates[tempCar][cnt] ;
            c2 = plates[i][cnt] ;
            if (c1 > c2) tempCar = i ;
        }
    }
    answer = plates[tempCar] ;
    //    cout << answer ;
    return answer;
}

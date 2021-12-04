#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for(int r=0;r<reserve.size();r++){
        if(find(lost.begin(), lost.end(), reserve[r])!=lost.end()) {
            lost.erase(find(lost.begin(), lost.end(), reserve[r]));
            reserve.erase(reserve.begin()+r);
            r--;
        }
    }
    for(int r=0;r<reserve.size();r++){
        for(int l=0;l<lost.size();l++){
            if(reserve[r]-1==lost[l] || reserve[r]+1==lost[l]) {
                lost.erase(lost.begin()+l);
                reserve.erase(reserve.begin()+r);
                r--;
                break;
            }
        }
    }
    return n-lost.size();
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> sizes) {
    int max_row=0, max_cal=0;
    for(vector<int> size:sizes) {
        max_row = max(max_row,size[0]);
        max_cal = max(max_cal,size[1]);
    }
    return max_row*max_cal;
}
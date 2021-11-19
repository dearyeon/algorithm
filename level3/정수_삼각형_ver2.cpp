#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> cnt = triangle;

    for(int i=cnt.size()-2;i>=0;i--) {
        for(int j=0;j<cnt[i].size();j++)
            cnt[i][j] += max(cnt[i+1][j], cnt[i+1][j+1]);
    }
    
    return cnt[0][0];
}
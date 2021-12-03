#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    sort(dungeons.begin(), dungeons.end());
    
    do {
        int n = k, count = 0;
        for(int i=0;i<dungeons.size();i++) {
            if(n >= dungeons[i][0]) {
                n -= dungeons[i][1];
                count++;
            }
        }
        answer = max(count, answer);
    } while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}
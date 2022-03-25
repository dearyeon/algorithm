#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <numeric>
using namespace std;

int scoreGap(vector<int> lion, vector<int> apeach) {
    int score1 = 0, score2 = 0;
    for(int i=0; i<11; i++) {
        if(lion[i] > apeach[i]) score1 += (10 - i);
        if(lion[i] < apeach[i]) score2 += (10 - i);
    }
    return score1 - score2;
};

bool isBetter(vector<int> cur, vector<int> answer) {
    if(answer.empty()) return false;
    for(int i=10; i>=0; i--)
        if(cur[i] != answer[i]) return cur[i] < answer[i];
    return false;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    int size = info.size();
    int maxGap = 0;
    
    queue<pair<int, vector<int> > > q;
    q.push(make_pair(0, vector<int>(size,0)));
    
    while(!q.empty()) {
        int idx = q.front().first;
        vector<int> temp = q.front().second;
        int count = n - accumulate(temp.begin(), temp.end(), 0); //남은 화살 개수
        q.pop();
        
        if(idx == size - 1) {
            temp[size - 1] += count;
            count = 0;
        }
        if(count == 0) { //큐 종료조건
            int gap = scoreGap(temp, info);
            if(gap >= maxGap || (gap == maxGap && isBetter(temp, answer))) {
                maxGap = gap;
                answer = temp;
            } 
            continue;
        } 
        
        if(info[idx] + 1 <= count) { //현재 idx에서 화살을 쏠 수 있을 때
            temp[idx] = info[idx] + 1;
            q.push(make_pair(idx + 1, temp));
        }
        temp[idx] = 0;
        q.push(make_pair(idx + 1, temp));
    }
    
    if(answer.empty() || scoreGap(answer, info) < 0 || maxGap == 0 ) answer = { -1 };
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    int day = 0;
    for(int progress : progresses)
        q.push(progress);
    
    while(!q.empty()) {
        int work = (99-q.front()) / speeds[0] +1;
        if(work > day) {
            day = work;
            answer.push_back(1);
        } else {
            answer.back()++;
        }
        q.pop();
        speeds.erase(speeds.begin());
    }
    
    return answer;
}
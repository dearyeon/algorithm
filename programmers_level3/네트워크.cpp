#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int visit[200] = { 0, };

void bfs(int i, vector<vector<int>> computers) {
    visit[i]=1;
    
    queue<int> q;
    q.push(i);
    
    while(!q.empty()) {
        int ii = q.front();
        q.pop();
        
        for(int jj=0;jj<computers.size();jj++) {
            
            if(jj<0 || jj>=computers.size() || visit[jj] || !computers[ii][jj])
                continue;
            
            visit[jj] = 1;
            q.push(jj);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<computers.size();i++) {
        if(!visit[i]) {
            bfs(i, computers);
            answer++;
        }
    }

    return answer;
}
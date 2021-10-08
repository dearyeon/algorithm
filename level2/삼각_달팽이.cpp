#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<vector<int> > pyramid;
int dx[] = {1,0,-1};
int dy[] = {0,1,-1};

void bfs() {
    int value = 1 , dir = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(0,0));
    pyramid[0][0]=value++;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<3;i++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx<0 || ny<0 || nx>=pyramid.size() || ny>=pyramid[nx].size() || pyramid[nx][ny]) {
                dir++;
                dir%=3;
                continue; 
            }

            q.push(make_pair(nx,ny));
            pyramid[nx][ny] = value++;
            
            break;
        }
    }
}

vector<int> solution(int n) {
    vector<int> answer;
    
    for(int i=1;i<=n;i++) {
        vector<int> v(i,0);
        pyramid.push_back(v);
    }
    
    bfs();
    
    for(int i=0;i<pyramid.size();i++) 
        answer.insert(answer.end(),pyramid[i].begin(),pyramid[i].end());
    
    return answer;
}
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int dx[] = {0,1,0,-1}; // 12시부터 시계방향
int dy[] = {-1,0,1,0};

int visit[100][100] = { 0 };
int cnt[100][100] = { 0 };

int bfs(vector<vector<int> > maps) {
    queue<pair<int, int> > q;
    int x=0, y=0;
    q.push(make_pair(x,y));
    visit[x][y] = 1;
    cnt[x][y]++;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx<0 || xx>=maps.size() || yy<0 || yy>=maps[xx].size() || maps[xx][yy]==0 || visit[xx][yy]==1) continue;
            q.push(make_pair(xx,yy));
            visit[xx][yy]=1;
            cnt[xx][yy] = cnt[x][y] + 1;
            if(xx == maps.size()-1 && yy == maps[xx].size()-1) return cnt[xx][yy];
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps) {
    return bfs(maps);
}
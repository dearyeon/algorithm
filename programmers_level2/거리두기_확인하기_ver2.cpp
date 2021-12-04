#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

int bfs(vector<string> place) {
    vector<vector<int> > visit(place.size(), vector<int>(place[0].length()));
    
    for(int x=0;x<place.size();x++) {
        for(int y=0;y<place[x].length();y++) {
        
            if(visit[x][y] || place[x][y] != 'P') continue;
    
            queue<pair<pair<int,int>, int> > q;
            q.push(make_pair(make_pair(x,y),0));
            visit[x][y] = 1;
            
            while(!q.empty()) {
                int xx = q.front().first.first;
                int yy = q.front().first.second;
                int cnt = q.front().second;
                q.pop(); 

                for(int i=0;i<4;i++) {
                    int nx = xx + dx[i];
                    int ny = yy + dy[i];

                    if(nx<0 || nx>=place.size() || ny<0 || ny>=place[nx].length() || visit[nx][ny] || place[nx][ny]=='X' || cnt==2) continue;
                    
                    q.push(make_pair(make_pair(nx,ny),cnt+1));
                    visit[nx][ny] = 1;
                    
                    if(place[nx][ny]=='P') return 0;
                    
                }
            }
        }
    }
    
    return 1;
}
vector<int> solution(vector<vector<string> > places) {
    vector<int> answer;
    for(int i=0;i<places.size();i++)
        answer.push_back(bfs(places[i]));
    return answer;
}
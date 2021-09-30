#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int dx[] = {0,1,0,-1}; //시계방향
int dy[] = {-1,0,1,0};

vector<int> solution(int m, int n, vector<vector<int> > picture) {
    vector<int> answer(2);
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<vector<int> > visit(m, vector<int>(n,0));
    
    for(int x=0;x<picture.size();x++) {
        for(int y=0;y<picture[x].size();y++) {
            if(visit[x][y]==0 && picture[x][y]!=0) {
                //bfs
                int area = 1, color = picture[x][y];
                visit[x][y] = 1;
                queue<pair<int, int> > q;
                q.push(make_pair(x,y));

                while(!q.empty()) {
                    int xx = q.front().first;
                    int yy = q.front().second;
                    q.pop();

                    for(int i=0;i<4;i++) {
                        int nx = xx + dx[i];
                        int ny = yy + dy[i];

                        if(nx<0 || nx>=picture.size() || ny<0 || ny>=picture[nx].size() || visit[nx][ny] || picture[nx][ny] != color) continue;

                        q.push(make_pair(nx,ny));
                        visit[nx][ny]=1;
                        area++;
                    }
                }
                if(max_size_of_one_area < area) max_size_of_one_area = area;
                number_of_area++;
            }
        }
    }
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
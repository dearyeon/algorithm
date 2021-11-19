#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int dx[] = {1, 1};
    int dy[] = {0, 1};
    
    int cnt[500][500] = { 0 };
    
    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    cnt[0][0] = triangle[0][0];
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<=1;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=triangle.size()) continue;
            
            if(cnt[nx][ny] < cnt[x][y] + triangle[nx][ny]) {
                cnt[nx][ny] = cnt[x][y] + triangle[nx][ny];
                q.push(make_pair(nx,ny));
                answer = max(answer, cnt[nx][ny]);
            }
        }
    }
    
    return answer;
}
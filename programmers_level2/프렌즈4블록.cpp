#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dx[3] = { 1, 1, 0 };
int dy[3] = { 0, 1, 1 };
int visit[30][30] = { 0 };

void blockBreak(int x, int y, vector<string> &board) {
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    visit[x][y] = 1;
    
    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        char block = board[xx][yy];
        q.pop();
        
        for(int i=0; i<3; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            
            if(xx >= board.size() || yy >= board[0].size() || block != board[xx][yy]) break;
            
            q.push(make_pair(nx,ny));
            visit[nx][ny] = 1;
            
            if(i == 2) {
                
            }
        }
    }
    
}
    
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    reverse(board.begin(), board.end());
    
    //blockBreak(m,n,board);
    for(string s : board)
        cout << s << endl;
    
    cout << "======" << endl;
    board[0][0] = '';
    for(string s : board)
        cout << s << endl;
    
    
    return answer;
}
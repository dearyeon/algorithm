#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//s.append(2,'*'); s에 2만큼 '*' 붙히기 메모하기!!!!!!
//s.erase(remove(s.begin(), s.end(), ' '), s.end()); remove -> 제거할 모든 인덱스 알려줌

int dx[3] = { 1, 1, 0 };
int dy[3] = { 0, -1, -1 };

void blockBreak(int x, int y, vector<string> &board, vector<string> &bomb, vector<vector<int> > &visit) {
    queue<vector<int> > q;
    q.push({x,y,board[x][y]});
    visit[x][y] = 1;
    
    while(!q.empty()) {
        int xx = q.front()[0];
        int yy = q.front()[1];
        char block = (char)q.front()[2];
        q.pop();
        
        for(int i=0; i<3; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            
            if(nx >= board.size() || ny < 0 || block != board[nx][ny]) break;
            
            q.push({nx,ny,board[nx][ny]});
            visit[nx][ny] = 1;
            
            if(i == 2) {
                bomb[xx][yy] = ' ';
                for(int i=0; i<3; i++)
                    bomb[xx+dx[i]][yy+dy[i]] = ' ';
            }
        }
    }
}
    
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    vector<string> v;
    for(int j=0; j<n; j++) {
        string s = "";
        for(int i=0; i<m; i++)
            s = board[i][j] + s;
        v.push_back(s);
    }
    
    while(true) {
        vector<string> bomb = v;
        vector<vector<int> > visit(30, vector<int>(30, 0));
        for(int i=0; i<v.size(); i++) {
            for(int j=v[i].length()-1; j>=1; j--) {
                if(!visit[i][j]) blockBreak(i, j, v, bomb, visit);
            }
        }          
        
        int bomb_count = 0;
        for(int i=0; i<bomb.size(); i++) {
            for(int j=0; j<bomb[i].length(); j++) {
                if(bomb[i][j] == ' ') {
                    bomb[i].erase(j--,1);
                    bomb_count++;
                }
            }
        }
        /*for(string s : bomb) {
            while(s.find(' ') != string::npos) {
                int start = s.find(' ');
                int end = start;
                while(s[end] == ' ') end++;
                bomb_count += (end - start);
                s.erase(start, end - start);
            }
        }*/
        answer += bomb_count;
        if(bomb_count == 0) break;
        v = bomb;
    }
    
    
    return answer;
}
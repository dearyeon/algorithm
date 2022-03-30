#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dx[3] = { 1, 1, 0 };
int dy[3] = { 0, -1, -1 };

void check(int x, int y, vector<string> v, vector<string> &bomb) {
    char block = v[x][y];
    for(int i=0; i<3; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        
        if(xx >= bomb.size() || yy < 0 || block != v[xx][yy]) break;
        
        if(i == 2) {
            bomb[x][y] = ' ';
            bomb[x+dx[0]][y+dy[0]] = ' ';
            bomb[x+dx[1]][y+dy[1]] = ' ';
            bomb[x+dx[2]][y+dy[2]] = ' ';
        }
    }
}

int blockErase(vector<string> &v, vector<string> &bomb) {
    int bomb_count = 0;
    for(int i=0; i<bomb.size(); i++) {
        while(bomb[i].find(' ') != string::npos) {
            int start = bomb[i].find(' ');
            int end = start;
            while(bomb[i][end] == ' ') end++;
            bomb_count += (end - start);
            bomb[i].erase(start, end - start);
        }
        v[i] = bomb[i];
    }
    return bomb_count;
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
        for(int i=0; i<v.size()-1; i++) {
            for(int j=v[i].length()-1; j>=1; j--)
                check(i,j,v,bomb);
        }          
        
        int bomb_count = blockErase(v,bomb);
        answer += bomb_count;
        if(bomb_count == 0) break;
    }
    
    
    return answer;
}
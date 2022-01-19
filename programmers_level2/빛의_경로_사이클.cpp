#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// 나한테 들어올 수 있는 경로 4개 
//   ↓          0
// →   ←      3   1
//   ↑          2

int visit[500][500][4] = { 0 };

int cycle(int i, int j, int k, vector<string> grid) {
    int len = 0;
    while(!visit[i][j][k]) {
        visit[i][j][k] = 1;
        switch(grid[i][j]) {
            case 'S':
                if(k==0) i++;
                else if(k==1) j--;
                else if(k==2) i--;
                else if(k==3) j++;
                break;
            case 'R':
                if(k==0) j--, k=1;
                else if(k==1) i--, k=2;
                else if(k==2) j++, k=3;
                else if(k==3) i++, k=0;
                break;
            case 'L':
                if(k==0) j++, k=3;
                else if(k==1) i++, k=0;
                else if(k==2) j--, k=1;
                else if(k==3) i--, k=2;
                break;
        }
        
        if(i == grid.size()) i = 0;
        if(j == grid[0].length()) j = 0;
        if(i < 0) i = grid.size()-1;
        if(j < 0) j = grid[0].length()-1;
        len++;
    }
    return len;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    for(int i=0;i<grid.size();i++) {
        for(int j=0;j<grid[0].length();j++) {
            for(int k=0;k<4;k++) {
                if(!visit[i][j][k]) {
                    int len = cycle(i,j,k,grid);
                    if(len>0) answer.push_back(len);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
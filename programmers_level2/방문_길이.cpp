#include <string>
#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    int visit[21][11] = { 0 };
    int x, y;
    char buf;
    
    if(dirs[0] == 'U') x = 9, y = 5, buf = 'U';
    else if(dirs[0] == 'D') x = 11, y = 5, buf = 'D';
    else if(dirs[0] == 'R') x = 10, y = 5, buf = 'R';
    else if(dirs[0] == 'L') x = 10, y = 4, buf = 'L';
    visit[x][y] = 1;
    answer++;
    
    dirs.erase(0,1);
    
    for(char c : dirs) {
        
        if(c == 'U' && x > 0) {
            if(buf == 'R') x--, y++;
            if(buf == 'L') x--;
            if(buf == 'U' && x > 2) x-= 2;
            buf = c;
        } else if(c == 'D' && x < 20) {
            if(buf == 'R') x++, y++;
            if(buf == 'L') x++;
            if(buf == 'D' && x < 19) x+=2;
            buf = c;
        } else if(c == 'R' && y < 11) {
            if(buf == 'U') x--;
            if(buf == 'D') x++;
            if(buf == 'R' && y < 9) y++;
            buf = c;
        } else if(c == 'L' && y > 0) {
            if(buf == 'U') x--, y--;
            if(buf == 'D') x++, y--;
            if(buf == 'L') y--;
            buf = c;
        } 
        if(!visit[x][y]) answer++;
        visit[x][y] = 1;
    }
    
    return answer;
}
#include <string>
#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    int visit[21][11] = { 0 };
    int x, y;
    char buf;
    // U - (9, 5)
    // D - (11, 5)
    // R - (10, 5)
    // L - (10, 4)
    if(dirs[0] == 'U') x = 9, y = 5, buf = 'U';
    else if(dirs[0] == 'D') x = 11, y = 5, buf = 'D';
    else if(dirs[0] == 'R') x = 10, y = 5, buf = 'R';
    else if(dirs[0] == 'L') x = 10, y = 4, buf = 'L';
    visit[x][y] = 1;
    answer++;
    
    dirs.erase(0,1);
    
    // U - D   D - U.   R - L.  L - R 같음
    // U - R (1, 0) -> (0, 0)    "-1, 0"    U - L (1,1) -> (0,0)  "+1, +1"
    // D - R (1,0) -> (2,0)    "+1, 0"  D - L (1,1) -> (2,0)  "+1, -1"
    // R - U (2,0) -> (1,1)   "-1, +1"   R - D (2,0) -> (3,1)  "+1, +1"
    // L - U (2,0) -> (1, 0)   "-1, 0"   L - D (2,0) -> (3,0)   "+1, 0"
    cout << buf << " (" << x << "," << y << ") " << answer << endl;
    
    for(char c : dirs) {
        if(c == 'U' && x > 0) {
            if(buf == 'R') x--, y++;
            if(buf == 'L') x--;
        } else if(c == 'D' && x < 20) {
            if(buf == 'R') x++, y++;
            if(buf == 'L') x++;
        } else if(c == 'R' && y < 10) {
            if(buf == 'U') x--;
            if(buf == 'D') x++;
        } else if(c == 'L' && y > 0) {
            if(buf == 'U') x++, y++;
            if(buf == 'D') x++, y--;
        }
        
        if(!visit[x][y]) answer++;
        cout << c << " (" << x << "," << y << ") " << answer << endl;
        visit[x][y] = 1;
    }
    
    return answer;
}
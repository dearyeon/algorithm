#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int> > matrix(rows, vector<int>(columns, 0));
    
    for(int i=0;i<queries.size();i++) {
        int x = queries[i][0]-1, y = queries[i][1], dir = 1;
        int prevalue = matrix[x][y-1] ? matrix[x][y-1] : x*columns+y;
        int _min = prevalue;
        
        while(dir!=0) {
            _min = min(_min, prevalue);
            
            int temp = matrix[x][y] ? matrix[x][y] : x*columns+y+1;
            matrix[x][y] = prevalue;
            prevalue = temp;
            
            if(dir==1) {
                if(y >= queries[i][3]-1) dir = 2;
                else y++;
            } 
            if (dir==2) {
                if(x >= queries[i][2]-1) dir = 3;
                else x++;
            } 
            if (dir==3) {
                if(y <= queries[i][1]-1) dir = 4;
                else y--;
            }
            if (dir==4) {
                if(x <= queries[i][0]-1) dir = 0;
                else x--;
            }
        }
        answer.push_back(_min);
    }
    return answer;
}
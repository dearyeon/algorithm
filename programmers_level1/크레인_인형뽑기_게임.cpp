#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
int solution(vector<vector<int> > board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    for(int x=0;x<moves.size();x++) {
        for(int y=0;y<board.size();y++) {
            if(board[y][moves[x]-1]>0) {
                if(!s.empty() && s.top() == board[y][moves[x]-1]) {
                    s.pop();
                    answer+=2;
                } else s.push(board[y][moves[x]-1]);
                board[y][moves[x]-1] = 0;
                break;
            }
        }
    }
    
    return answer;
}
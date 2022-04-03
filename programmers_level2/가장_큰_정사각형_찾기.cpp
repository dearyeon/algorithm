#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board) {
    int n = board[0][0];
    
    for(int i=1; i<board.size(); i++) {
        for(int j=1; j<board[i].size(); j++) {
            if(board[i][j]) {
                board[i][j] = 1 + min({board[i-1][j-1], board[i-1][j], board[i][j-1]});
                n = max(n, board[i][j]);
            }
        }
    }

    return n*n;
}
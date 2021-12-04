#include <string>
#include <vector>
#include <iostream>
using namespace std; 
vector<int> solution(vector<vector<string> > places) {
    vector<int> answer;
    for(int i=0;i<5;i++) {
        int isgood = 1;
        for(int j=0;j<5;j++) { 
            for(int k=0;k<5;k++) {
                if(places[i][j][k]=='P') { 
                    if(((k<4 && places[i][j][k+1]=='P') || (k>0 && places[i][j][k-1]=='P'))) {
                        isgood = 0;
                        break;
                    } 
                    if(((k<3 && places[i][j][k+2]=='P' && places[i][j][k+1]!='X') || (k>1 && places[i][j][k-2]=='P' && places[i][j][k-1]!='X'))) {
                        isgood = 0;
                        break;
                    }
                    if(j>0) {
                        if(places[i][j-1][k]=='P' || (k<4 && places[i][j-1][k+1]=='P' && (places[i][j-1][k]!='X' || places[i][j][k+1]!='X')) || (k>0 && places[i][j-1][k-1]=='P' && (places[i][j-1][k]!='X' || places[i][j][k-1]!='X'))) {
                            isgood = 0;
                            break;
                        }
                    }
                    if(j>1 && places[i][j-2][k]=='P' && places[i][j-1][k]!='X') {
                            isgood = 0;
                            break;
                    }
                }
            }
        }
        answer.push_back(isgood);
    }
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    
    string s = "ACFJMNRT";
    
    do {
        bool isgood = true;
        for(string d : data) {
            int idx1 = s.find(d[0]);
            int idx2 = s.find(d[2]);
            if((d[3] == '=' && abs(idx1 - idx2) != d[4]-'0'+1) || (d[3] == '>' && abs(idx1 - idx2) <= d[4]-'0'+1) || (d[3] == '<' && abs(idx1 - idx2) >= d[4]-'0'+1)) {
                isgood = false;
                break;
            }
        }
        if(isgood) answer++;
    } while(next_permutation(s.begin(), s.end()));
    return answer;
}
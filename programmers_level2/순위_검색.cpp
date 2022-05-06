#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    vector<vector<string> > v;
    for(string s : info) {
        vector<string> temp;
        int pos = 0;
        while(s.find(' ',pos) != string::npos) {
            int len = s.find(' ',pos);
            temp.push_back(s.substr(pos, len - pos));
            pos = len + 1;
        }
        temp.insert(temp.begin(), s.substr(pos));
        v.push_back(temp);
    }
    
    for(string s : query) {
        int isGood = 0;
        
        vector<string> temp;
        int pos = 0;
        while(s.find(' and ',pos) != string::npos) {
            int len = s.find(' and ',pos);
            temp.push_back(s.substr(pos, len - pos));
            pos = len + 5;
        }
        temp.insert(temp.begin(), s.substr(pos-4));
        
        for(int i=0; i<v.size(); i++) {
            if(stoi(v[i][0]) < stoi(temp[0])) continue;
            
            int j;
            for(j=1; j<5; j++)
                if(temp[j] != "-" && v[i][j] != temp[j]) break;
            if(j == 5) isGood++;
        }
        
        answer.push_back(isGood);
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    map<string, vector<int> > m;
    map<string, vector<int> >::iterator it;
    for(int i=0; i<info.size(); i++) {
        string s = "";
        int pos = 0;
        while(info[i].find(' ',pos) != string::npos) {
            int len = info[i].find(' ',pos);
            s += info[i].substr(pos, len - pos);
            pos = len + 1;
        }
        m[s].push_back(stoi(info[i].substr(pos)));
    }
    
    for(it=m.begin(); it!=m.end(); it++)
        sort(it->second.begin(), it->second.end(), greater<int>());
    
    for(string q : query) {
        int isGood = 0;
        int score = stoi(q.substr(q.rfind(' ')));
        string s = "";
        
        vector<string> temp;
        int pos = 0;
        for(int i=0; i<3; i++) {
            int len = q.find(" and ",pos);
            string word = q.substr(pos, len - pos);
            if(word == "-") s += to_string(i);
            else s += word;
            pos = len + 5;
        }
        s += q.substr(pos, q.find(' ',pos)-pos);
        answer.push_back(isGood);
    }
    
    return answer;
}
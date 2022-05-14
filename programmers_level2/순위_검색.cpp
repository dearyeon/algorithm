#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

map<string, vector<int> > m;
map<string, vector<int> >::iterator it;

void putOnMap(vector<string> info) {
    for(int i=0; i<info.size(); i++) {
        string cond[4];
        int pos = 0;
        
        for(int i=0; i<3; i++) {
            int len = info[i].find(" ",pos);
            cond[i] = info[i].substr(pos, len - pos);
            pos = len + 5;
        }
        cond[3] = info[i].substr(pos, info[i].find(' ',pos)-pos);
        cout << cond[0] << cond[1] << cond[2] << cond[3] << endl;
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    putOnMap(info);
    
    //for(it=m.begin(); it!=m.end(); it++)
    //    sort(it->second.begin(), it->second.end(), greater<int>());
    for(string q : query) {
        int score = stoi(q.substr(q.rfind(' ')));
        string s = "";

        vector<string> temp;
        int pos = 0;
        for(int i=0; i<3; i++) {
            int len = q.find(" and ",pos);
            s += q.substr(pos, len - pos);
            pos = len + 5;
        }
        s += q.substr(pos, q.find(' ',pos)-pos);
        cout << s << endl;
    }
    
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(string expression) {
    long long answer = 0;
    
    char cases[6][3] = {
        {'+','-','*'},
        {'+','*','-'},
        {'-','+','*'},
        {'-','*','+'},
        {'*','+','-'},
        {'*','-','+'}};
    vector<long long> _num;
    vector<char> _cur;
    
    string s = "";
    for(char c : expression) {
        if(c == '+' || c == '-' || c == '*') {
            _cur.push_back(c);
            _num.push_back(stoll(s));
            s = "";
        } else s += c;
    }
    _num.push_back(stoll(s));
    
    for(int i=0; i<6; i++) {
        vector<long long> num = _num;
        vector<char> cur = _cur;
        for(int j=0; j<3; j++) {
            while (find(cur.begin(), cur.end(), cases[i][j]) != cur.end()) {
                int idx = find(cur.begin(), cur.end(), cases[i][j]) - cur.begin();
                if(cases[i][j] == '+') num[idx] += num[idx+1];
                else if(cases[i][j] == '-') num[idx] -= num[idx+1];
                else if(cases[i][j] == '*') num[idx] *= num[idx+1];
                num.erase(num.begin()+idx+1);
                cur.erase(cur.begin()+idx);
            }
        }
        answer = max(answer, abs(num[0]));
    }
    return answer;
}
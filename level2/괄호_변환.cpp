#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

bool isgood(string t) {
    stack<char> s;
    for(int i=0;i<t.length();i++) {
        if(t[i]==')' && !s.empty() && s.top()=='(') s.pop();
        else s.push(t[i]);
    }
    return s.empty();
}

string solution(string w) {
    
    if(w == "") return "";
    
    string u,v;
    int begin=0, end=0;
    for(int i=0;i<w.length();i++) {
        w[i]=='(' ? begin++ : end++;
        if(begin==end) {
            u = w.substr(0,i+1);
            v = w.substr(i+1);
            break;
        }
    }
    
    if(isgood(u)) return u + solution(v);
    else {
        string answer = "(" + solution(v) + ")";
        u = u.substr(1,u.length()-2);
        for(int i=0;i<u.length();i++)
            u[i] = u[i]=='(' ? ')' : '(';
        answer += u;
        return answer;
    }
}
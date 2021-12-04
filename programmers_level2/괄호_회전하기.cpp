#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i=0;i<s.length();i++) {
        stack<char> check;
        for(char c : s) {
            if(check.empty()) check.push(c);
            else if(c=='}' && check.top()=='{') check.pop();
            else if(c==']' && check.top()=='[') check.pop();
            else if(c==')' && check.top()=='(') check.pop();
            else check.push(c);
        }
        if(check.size() == 0) answer++;
        s += s[0];
        s.erase(0,1);
    }
    return answer;
}
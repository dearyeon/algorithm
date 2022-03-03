#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s) {
    stack<int> b;
    for(char c : s) {
        if(c == '(') b.push(1);
        else if(c == ')') {
            if(b.empty() || b.top() == 0) return false;
            else if(!b.empty() && b.top() == 1) b.pop();
        }
    }
    return b.empty();
}
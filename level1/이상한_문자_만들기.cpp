#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    for(int i=0;i<s.length();i++) {
        if(s[i] == ' ') {
            answer+=" ";
            s.erase(0,i+1);
            i=-1;
            continue;
        }
        answer += i%2==0 ? toupper(s[i]) : tolower(s[i]);
    }
    return answer;
}
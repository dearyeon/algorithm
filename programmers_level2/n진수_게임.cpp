#include <string>
#include <vector>
#include <iostream>
using namespace std;
string convert(int n, int b) {
    string result = "";
    while(n > 0) {
        if(n % b < 10) result = (char)(n % b + 48) + result; //아스키코드 0 -> 48
        else result = (char)(n % b + 55) + result; //아스키코드 A -> 65인데 10이상이므로
        n /= b;
    }
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int num = 1;
    string buf = "0";
    
    while(answer.length() < t) {
        if(buf.length() < m) buf += convert(num++, n);
        else {
            answer += buf[p-1];
            buf.erase(0, m);
        }
    }
    
    return answer;
}
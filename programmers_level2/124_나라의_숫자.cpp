#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
    string answer = "";
    char digit[3] = { '1', '2', '4' };
    
    while(n>0) {
        n--;
        answer = digit[n%3] + answer;
        n/=3;
    }
    
    return answer;
}
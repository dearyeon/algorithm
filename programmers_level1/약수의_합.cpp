#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1;i<=sqrt(n);i++) {
        if(n%i==0) {
            answer+=i;
            answer+=(n/i);
        }
        if(i==sqrt(n)) answer-=i;
    }
    return answer;
}
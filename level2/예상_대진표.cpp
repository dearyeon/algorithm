#include <iostream>
#include <cmath>
using namespace std;
int solution(int n, int a, int b) {
    int answer = 0;
    while(a!=b) {
        n/=2;
        if(a%2) a++;
        if(b%2) b++;
        a/=2;
        b/=2;
        answer++;
    }
    return answer;
}
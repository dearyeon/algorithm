#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 1;
    for(int i=2;i<=n;i++) {
        if(i*(i+1)/2 > n) break;
        if(i%2 == 0 && n%i == i/2) answer++;
        if(i%2 && n%i == 0) answer++;
    }
    return answer;
}
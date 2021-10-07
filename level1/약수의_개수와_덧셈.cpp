#include <string>
#include <vector>
#include <iostream>
using namespace std;

int a(int num) {
    int answer = 0;
    for(int i=1;i<=num/i;i++){
        if(i*i==num) answer++;
        else if(num%i==0) answer+=2;
    }
    return answer;
}

int solution(int left, int right) {
    int answer = 0;
    for(int i=left;i<=right;i++) {
        if(a(i)%2==0) answer+=i;
        else answer-=i;
    }
    return answer;
}
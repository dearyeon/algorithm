#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int one_count(int n) {
    int count = 0;
    while(n!=0) {
        if(n%2) count++;
        n/=2;
    }
    return count;
}

int solution(int n) {
    int answer = n+1;
    int oc = one_count(n);
    while(1) {
        if(oc == one_count(answer)) break;
        else answer++;
    }
    return answer;
}
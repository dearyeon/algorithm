#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    int i=0;
    while(a.size()>i)
        answer+=(a[i]*b[i++]);
    return answer;
}
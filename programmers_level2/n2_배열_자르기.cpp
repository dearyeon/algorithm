#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long i=left; i<=right; i++) {
        int x = i % n + 1;
        int y = i / n + 1;
        answer.push_back(max(x,y));
    }
    return answer;
}
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int a) {
    int answer = 0;
    queue<int> q;
    q.push(0);
    q.push(1);
    for(int i=2;i<=a;i++) {
        int n, n_1, n_2;
        n_1 = q.front();
        q.pop();
        n_2 = q.front();
        n = (n_1 + n_2) % 1234567;
        q.push(n);
        answer = n;
    }
        
    return answer % 1234567;
}
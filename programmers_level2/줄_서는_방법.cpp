#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> left;
    long long m = 1;
    
    for(int i=1; i<=n; i++) {
        left.push_back(i);
        m *= i;
    }
    m /= n;
    k--;
    
    for(int i=n-1; i>0; i--) {
        answer.push_back(left[k / m]);
        left.erase(left.begin() + (k / m));
        k %= m;
        m /= i;
    }
    answer.push_back(left.back());
    
    return answer;
}
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = n;
    int na =0;
    vector<bool> checked(n, false);
    
    for(int i=2;i<=n;i++) {
        for(int j=2*i;j<=n;j+=i) {
            if(!checked[j-1]) {
                checked[j-1]=true;
                na++;
            }
        }
    }
    
    answer-=(na+1);
    return answer;
}
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for(long long a : numbers) {
        if(a & 1) {
            long long aa = a;
            int where = 0;
            while(aa) {
                if ((aa & 1) == 0) break;
                aa >>= 1;
                where++;
            }
            answer.push_back(a + pow(2, where) - pow(2, where-1));
        } else answer.push_back(a+1);
    }
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long m = sqrt(n);
    return m == sqrt(n) ? (m+1)*(m+1) : -1;
}
#include <iostream>
using namespace std;
long long solution(int price, int money, int count) {
    long long answer = (long long)price * (count * (count+1) / 2) - money;
    return answer >= 0 ? answer : 0;
}
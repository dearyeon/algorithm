#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2,0);
    
    while(s != "1") {
        sort(s.begin(), s.end());
        answer[1] += s.find('1');
        s.erase(0, s.find('1'));
        string temp = bitset<1000>(s.length()).to_string();
        temp.erase(0, temp.find('1'));
        s = temp;
        answer[0]++;
    }
    
    return answer;
}
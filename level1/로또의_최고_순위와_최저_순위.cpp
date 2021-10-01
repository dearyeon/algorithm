#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int a=0, zero=0;
    for(int i:lottos) {
        if(i==0) zero++;
        else if(find(win_nums.begin(), win_nums.end(),i) != win_nums.end()) a++;
    }
    (7-a-zero) < 6 ? answer.push_back(7-a-zero) : answer.push_back(6);
    (7-a) < 6 ? answer.push_back(7-a) : answer.push_back(6);
    return answer;
}
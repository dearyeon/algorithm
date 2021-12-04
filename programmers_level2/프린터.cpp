#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int> > printer;
    for(int i=0;i<priorities.size();i++)
        printer.push(make_pair(priorities[i],i)); // <prioritie, location>
    
    sort(priorities.begin(), priorities.end(), greater<>());
    
    while(!priorities.empty()) {
        int first = printer.front().first; //prioritie
        int second = printer.front().second; //location
        printer.pop();
        
        if(priorities[0] > first) printer.push(make_pair(first, second));
        else {
            answer++;
            priorities.erase(priorities.begin());
            if(second == location) return answer;
        }
    }
    
    return answer;
}
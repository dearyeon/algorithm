#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int count = people.size();
    
    priority_queue <int, vector<int>, less<int> > pq_l;
    priority_queue <int, vector<int>, greater<int> > pq_g;
    
    for(int p : people) {
        pq_l.push(p);
        pq_g.push(p);
    }
        
    while(count) {
        if(pq_l.top() + pq_g.top() <= limit && count >= 2) {
            pq_l.pop();
            pq_g.pop();
            count -= 2;
        } else {
            pq_l.pop();
            count--;
        }
        answer++;
    }
    
    return answer;
}
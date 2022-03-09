#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include <queue>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    
    if(sum == target) return 1;
    if(sum < target) return 0;
    cout << sum << endl;
    
    queue<pair<int, int> > q; //acc, index
    q.push(make_pair(sum, 0));
    
    while(!q.empty()) {
        int acc = q.front().first;
        int index = q.front().second;
        q.pop();
        
        if(index >= numbers.size()) continue;
        
        if(acc - numbers[index] * 2 == target) answer++;
        
        if(acc - numbers[index] * 2 > target)
            q.push(make_pair(acc - numbers[index] * 2, index+1));
        
        q.push(make_pair(acc, index+1));
        
    }
    
    return answer;
}
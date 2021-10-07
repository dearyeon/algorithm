#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> temp;
    
    while(n!=0){
        temp.push_back(n%3);
        n=n/3;
    }
    
    int a=temp.size();
    for(int i=0;i<a;i++){
        answer+=temp.back()*((int)pow(3,i));
        temp.pop_back();
    }
    
    return answer;
}
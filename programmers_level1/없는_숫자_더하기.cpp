#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int solution(vector<int> numbers) {
    int answer=0, j=0;
    
    sort(numbers.begin(), numbers.end());
    
    for(int i=0;i<=9;i++) {
        if(i!=numbers[j++]) {
            answer+=i;
            j--;   
        }
    }
    return answer;
}
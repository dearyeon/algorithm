#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool sosu(int n) {
    if(n <= 1) return false;
    
    for(int i=2; i<=sqrt(n); i++)
        if(n % i == 0) return false;
    
    return true;
}

int solution(string numbers) {
    vector<int> answer;
    
    sort(numbers.begin(), numbers.end());
    
    for(int r=1; r<=numbers.length(); r++) {
        vector<bool> v(numbers.length(), true);
        for(int i=0; i<v.size()-r; i++)
            v[i] = false;

        do {
            string s = "";
            for(int i=0;i<v.size();i++)
                if(v[i]) s += numbers[i];
            do {
                if(sosu(stoi(s))) answer.push_back(stoi(s));
            } while(next_permutation(s.begin(), s.end()));
            
        } while(next_permutation(v.begin(), v.end()));
    }
    
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    
    return answer.size();
}
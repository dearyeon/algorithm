#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();
    int pass = 0;
    
    for(int i=0; i<n; i++) {
        answer += name[i] <= 78 ? name[i] - 'A' : 'Z' - name[i] + 1;
        
        int ind = i + 1;
        while(ind < n && name[ind] == 'A') ind++;
        int cur_pass = min(i, n - ind) - (ind - i - 1);
        pass = min(pass, cur_pass);
        
        answer++;
    }
    
    return --answer + pass;
}
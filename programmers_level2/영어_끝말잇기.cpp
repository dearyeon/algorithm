#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    map<string, int> m;
    
    m[words[0]]++;
    for(int i=1;i<words.size();i++) {
        if(m[words[i]] || words[i-1][words[i-1].length()-1] != words[i][0])
            return {i%n+1,i/n+1};
        m[words[i]]++;
    }
    
    return {0,0};
}
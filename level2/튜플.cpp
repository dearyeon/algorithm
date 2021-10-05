#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> solution(string s) {
    vector<int> answer;
    vector<string> store(500, "");
    
    int idx = 2;
    
    while(idx < s.length()) {
        string cur1 = s.substr(idx,s.find("}",idx)-idx);
        string cur2 = cur1;
        int count = 0;
        sort(cur2.begin(), cur2.end());
        for(char c:cur2) {
            if(c==',') count++;
            else break;
        }
        store[count] = cur1;
        idx = s.find("}", idx)+3;
    }
    
    for(int i=0;i<store.size();i++) {
        if(store[i] == "") break;
        string buf = "";
        for(int j=0;j<store[i].length();j++) {
            if(store[i][j]!=',') buf += store[i][j];
            if(store[i][j]==',' || j==store[i].length()-1) {
                int num = stoi(buf);
                if(find(answer.begin(),answer.end(),num)==answer.end())
                    answer.push_back(num);
                buf = "";
            }
        }
    }
    
    return answer;
}
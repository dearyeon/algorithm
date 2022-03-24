#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<string, int> ii; //이거 메모하기!!!!!!!!!!!!!

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int r : course) {

        map<string, int> set;
        
        for(string order : orders) {
            if(r > order.length()) continue;
            
            sort(order.begin(), order.end());
            
            vector<bool> v(order.length(), true);
            for(int i=0; i<order.length()-r; i++)
                v[i] = false;
            
            do{
                string s = "";
                for(int j=0; j<v.size(); j++)
                    if(v[j]) s += order[j];
                set[s]++;
            } while(next_permutation(v.begin(), v.end()));
        }
        
        int max = 0;
        vector<ii> temp(set.begin(), set.end());
        sort(temp.begin(), temp.end(), [](ii a, ii b) {
            return a.second > b.second;
        });
        for(ii a : temp) {
            if(a.second < max || a.second == 1) break;
            max = a.second;
            answer.push_back(a.first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
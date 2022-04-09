#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool incld (string &key, vector<string> &answer) {
    int i;
    for(i=0; i<answer.size(); i++) {
        int j;
        for(j=0; j<answer[i].length(); j++)
            if(key.find(answer[i][j]) == string::npos) break;
        if(j == answer[i].length()) return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    vector<string> answer;
    
    int n = relation[0].size();
    for(int r=1; r<=n; r++) {
        vector<bool> v(n, false);
        for(int i=n-r; i<n; i++)
            v[i] = true;

        do {
            string key = ""; 
            for(int i=0; i<n; i++)
                if(v[i]) key += to_string(i);
            
            if(!incld(key, answer)) continue;
            
            map<string, int> m;
            int i;
            for(i=0; i<relation.size(); i++) {
                string s = "";
                for(int j=0; j<key.length(); j++)
                    s += relation[i][key[j] - '0'] + " ";
                m[s]++;
                if(m[s] > 1) break;
            }
            if(i == relation.size()) answer.push_back(key);
        } while(next_permutation(v.begin(), v.end()));
    }
    
    return answer.size();
}
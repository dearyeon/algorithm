#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int convertMin(string t) {
    int t_hour = stoi(t.substr(0,2)), t_min = stoi(t.substr(3,2));
    return t_hour*60 + t_min;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> m;
    map<string, int>::iterator it;
    vector<string> parking;
    vector<int> inTime;
    
    for(string s : records) {
        string time = s.substr(0,5);
        string num = s.substr(6,4);
        string state = s.substr(11);
        
        if(state == "IN") {
            parking.push_back(num);
            inTime.push_back(convertMin(time));
        }
        
        if(state == "OUT") {
            int idx = find(parking.begin(), parking.end(), num) - parking.begin();
            m[num] += convertMin(time) - inTime[idx];
            parking.erase(parking.begin()+idx);
            inTime.erase(inTime.begin()+idx);
        }
    }
    
    for(int i=0; i<parking.size(); i++)
        m[parking[i]] += convertMin("23:59") - inTime[i];
    
    for(it=m.begin(); it!=m.end(); it++) {
        int fee = fees[1];
        if(it->second > fees[0]) fee += (it->second - fees[0] + fees[2] - 1) / fees[2] * fees[3];
        answer.push_back(fee);
    }
    
    return answer;
}
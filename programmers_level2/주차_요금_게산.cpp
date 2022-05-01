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
            m[time] += convertMin(time) - inTime[idx];
            cout << time << " " << num << " " << m[time] << endl;
        }
    }
    
    return answer;
}
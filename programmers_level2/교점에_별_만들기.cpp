#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmpX(pair<long long, long long> &a, pair<long long, long long> &b) {
    return a.first < b.first;
}
bool cmpY(pair<long long, long long> &a, pair<long long, long long> &b) {
    return a.second < b.second;
}
vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<long long, long long> > v;
    long long minX, minY, maxX, maxY;
    
    for(int i=0; i<line.size(); i++) {
        for(int j=i+1; j<line.size(); j++) {
            long long m = (long long)line[i][0]*line[j][1] - (long long)line[i][1]*line[j][0];
            if(m == 0) continue;
            
            long long nx = (long long)line[i][1]*line[j][2] - (long long)line[i][2]*line[j][1];
            long long ny = (long long)line[i][2]*line[j][0] - (long long)line[i][0]*line[j][2];
            if(nx%m == 0 && ny%m == 0)
                v.push_back(make_pair(nx/m, ny/m));
        }
    }
    v.erase(unique(v.begin(), v.end()), v.end());
    
    sort(v.begin(), v.end(), cmpX);
    minX = v[0].first, maxX = v[v.size()-1].first;
    sort(v.begin(), v.end(), cmpY);
    minY = v[0].second, maxY = v[v.size()-1].second;
    
    string s = "";
    while(minX <= maxX--) s += ".";
    while(minY++ <= maxY) answer.push_back(s);
    
    for(int i=0; i<v.size(); i++) 
        answer[maxY - v[i].second][v[i].first - minX] = '*';
    
    return answer;
}
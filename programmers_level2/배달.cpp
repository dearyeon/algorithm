#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    sort(road.begin(), road.end());
    
    vector<int> v(N+1, -1);
    map<int, vector<pair<int, int> > > m;
    for(int i=0; i<road.size(); i++) {
        m[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        m[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }
    queue<int> q;
    q.push(1);
    v[1] = 0;

   while(!q.empty()) {
        int M = q.front();
        q.pop();
       
       if(v[M] == -1) continue;

        for(int i=0; i<m[M].size(); i++) {
            int cmpM = m[M][i].first;
            int r = m[M][i].second;
            if(v[cmpM] == -1 || v[cmpM] > v[M] + r) {
                v[cmpM] = v[M] + r;
                q.push(cmpM);
            }
        }
    }
    
    for(int i=1; i<N+1; i++)
        if(v[i] <= K) answer++;

    return answer;
}
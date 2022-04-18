#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

void link(vector<vector<int> > road, vector<int> &v) {
    for(vector<int> r : road) {
        v[r[0]-1] = min(v[r[0]-1], v[r[1]-1] + r[2]);
        v[r[1]-1] = min(v[r[1]-1], v[r[0]-1] + r[2]);
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    sort(road.begin(), road.end());
    vector<int> v(N+1, 0);
    map<int, vector<pair<int, int> > > m;
    queue<int> q;
    q.push(1);
    

   while(!q.empty()) {
       int M = q.front();
       q.pop();
       
        for(int i=0; i<road.size(); i++) {
            if(road[i][0] != M && road[i][1] != M) continue;
            
            int a = M;
            int b = road[i][0] == M ? road[i][1] : road[i][0];
            int cmp = v[M] + road[i][2];
            
            v[b] = v[b] ? min(v[b],cmp) : cmp;
            //v[a] = min(v[a],v[b]+road[i][2]);
            if(v[a] > v[b]+road[i][2]) {
                v[a] = v[b]+road[i][2];
                for(int j=0; j<m[a].size(); j++)
                    v[m[a][i].first] = min(v[m[a][i].first], v[a]+m[a][i].second);
            }
            q.push(b);
            cout << "v["<<a<<"]:"<< v[a] << "  " <<"v["<<b<<"]:"<< v[b] << endl;
            m[a].push_back(make_pair(b,road[i][2]));
            m[b].push_back(make_pair(a,road[i][2]));
            road.erase(road.begin()+i--);
            
        }
       
    }
    
    for(int i=1; i<N+1; i++) {
        cout << v[i] << " ";
        if(v[i] <= K) answer++;
    }

    return answer;
}
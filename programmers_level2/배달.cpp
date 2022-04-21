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
    for(int i=0; i<road.size(); i++) {
        m[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        m[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }
    queue<int> q;
    q.push(1);
    

   while(!q.empty()) {
        int M = q.front();
        q.pop();

        int r = v[M]; // + road[i][2];

        if(v[M] > r) {
            v[M] = r;
        }
        //q.push(b);
        cout << "v["<<M<<"]:"<< v[M] << endl;
    }
    
    for(int i=1; i<N+1; i++) {
        cout << v[i] << " ";
        if(v[i] <= K) answer++;
    }

    return answer;
}
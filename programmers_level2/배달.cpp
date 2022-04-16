#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void link(vector<vector<int> > road, vector<int> &v) {
    for(vector<int> r : road) {
        v[r[1]-1] = min(v[r[1]-1], v[r[0]-1] + r[2]);
        v[r[0]-1] = min(v[r[0]-1], v[r[1]-1] + r[2]);
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    sort(road.begin(), road.end());
    vector<int> v(N, 50001);
    v[0] = 0;

    link(road, v);
    link(road, v);
    
    for(int i=0; i<N; i++) {
        //cout << v[i] << " ";
        if(v[i] <= K) answer++;
    }

    return answer;
}
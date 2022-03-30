#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int checkCount(int w1, int w2, int n, vector<vector <int> > v) {
    vector<int> check(n, 0);
    int count = 0;
    
    queue<int> q;
    q.push(w1);
    while(!q.empty()) {
        int w = q.front();
        q.pop();
        
        if(w == w2 || check[w] == 1) continue;
        
        for(int i=0; i<v.size(); i++) {
            if(i == w2) continue;
            if(v[w][i] == 1) q.push(i);
        }
        check[w] = 1;
    }
    
    for(int i=0; i<n; i++)
        if(check[i]) count++;
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    vector<vector <int> > v(n, vector<int>(n, 0));
    
    for(int i=0; i<n-1; i++) {
        v[wires[i][0]-1][wires[i][1]-1] = 1;
        v[wires[i][1]-1][wires[i][0]-1] = 1;
    }
    
    for(int i=0; i<n-1; i++) {
        int count = checkCount(wires[i][0]-1, wires[i][1]-1, n, v);
        
        answer = answer == -1 ? abs(count*2-n) : min(answer, abs(count*2-n));
    }
    
    return answer;
}
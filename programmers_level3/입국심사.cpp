#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    
    LL low = 1; //최소시간
    LL high = (LL)times.back() * n; //최대시간
    LL mid;
    
    while(low <= high) {
        LL cnt = 0;
        mid = (low + high) / 2;
        
        for(int time : times)
            cnt += mid / (LL)time;
        
        if(cnt >= n) high = mid - 1;
        else low = mid + 1;
    }

    return low;
}
/*
typedef long long LL;
typedef pair<LL, LL> PLL;

long long solution(int n, vector<int> times) {
    LL answer = 0;
    priority_queue<PLL, vector<PLL>, greater<PLL> > pq; //endTime, time

    for(int time : times) 
        pq.push(make_pair(time,time));

    for(int i=0; i<n; i++) {
        LL endTime = pq.top().first;
        LL time = pq.top().second;
        answer = endTime;
        pq.pop();
        pq.push(make_pair(endTime+time, time));
    }
        
    return answer;
}*/
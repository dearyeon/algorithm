#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0, size = jobs.size();
    sort(jobs.begin(), jobs.end());
    
    while(!jobs.empty()) {
        int process_job = 0, process_time;
        
        if(jobs[0][0] <= time) {
            process_time = time + jobs[0][1] -jobs[0][0];
            int min_time = jobs[0][1];
            for(int i=1; i<jobs.size(); i++) {
                if(jobs[i][0] > time) break;
                
                int temp = time + jobs[i][1] - jobs[i][0];
                if(min_time > jobs[i][1]) {
                    process_job = i;
                    process_time = temp;
                    min_time = jobs[i][1];
                }
            }
            
            time += jobs[process_job][1];
        } else {
            process_time = jobs[0][1];
            time = jobs[0][0] + jobs[0][1];
        }
        
        answer += process_time;
        jobs.erase(jobs.begin() + process_job);
    }
    
    return answer / size;
}
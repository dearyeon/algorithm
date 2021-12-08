#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
// 해결 => 캐시가 다 안 채워졌을 때 또 같은 값이 들어올 경우, 그 값을 제일 최상단으로 옮겨야 합니다.
int solution(int cacheSize, vector<string> cities) {
    
    if(cacheSize == 0) return 5 * cities.size();
    
    int answer = 0;
    vector<string> cache;
    map<string, bool> m;
    
    for(string city : cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        if(m[city]) { // cache hit
            cache.erase(find(cache.begin(), cache.end(), city));
            cache.insert(cache.begin(), city);
            answer++;
        } else { // cache miss
            if(cache.size() >= cacheSize) {
                m[cache.back()] = false;
                cache.pop_back();
            }
            cache.insert(cache.begin(), city);
            m[city] = true;
            answer += 5;
        }
    }
    return answer;
}
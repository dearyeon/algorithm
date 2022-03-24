#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=1; i<=sqrt(yellow); i++) {
        if(yellow % i == 0) {
            int x = yellow / i;
            int y = i;
            if((x+2)*(y+2) == brown + yellow) {
                answer.push_back(x+2);
                answer.push_back(y+2);
                break;
            }
        }
    }
    return answer;
}
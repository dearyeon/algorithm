#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int day[]= {31,29,31,30,31,30,31,31,30,31,30,31};
    string week[] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int daysum = 0;
    for(int i=0;i<a-1;i++)
        daysum+=day[i];
    daysum+=b-1;
    return week[daysum%7];
}
#include <string>
#include <vector>
using namespace std;

int solution(int n) { 
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    for(int i=2; i<=n; i++)
        v.push_back((v[i-2] + v[i-1]) % 1000000007);
    return v[n];
}
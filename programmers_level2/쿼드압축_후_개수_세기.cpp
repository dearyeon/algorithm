#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int one = 0;
int zero = 0;

void compression(vector<vector<int>> &arr, int x, int y, int n) {
    int i;
    int j = arr[x][y] ? 0 : 1;
    for(i=x; i<x+n; i++)
        if(find(arr[i].begin()+y, arr[i].begin()+y+n, j) != arr[i].begin()+y+n) break;
    
    if(i == x+n) j ? zero++ : one++;
    else {
        compression(arr, x, y, n/2);
        compression(arr, x, y+n/2, n/2);
        compression(arr, x+n/2, y, n/2);
        compression(arr, x+n/2, y+n/2, n/2);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    compression(arr, 0, 0, arr.size());
    return {zero, one};
}
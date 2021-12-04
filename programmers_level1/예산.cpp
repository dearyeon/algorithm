#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int sum = 0;
    sort(d.begin(), d.end());
    int i;
    for(i=0;i<d.size();i++){
        if(d[i]+sum<=budget) sum+=d[i];
        else break;
    }
    return i;
}
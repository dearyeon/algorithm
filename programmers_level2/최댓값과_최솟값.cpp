#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s) {
    vector<int> arr;
    int idx=0;
    
    do {
        arr.push_back(stoi(s.substr(idx, s.find(" ",idx)-idx)));
        idx = s.find(" ",idx)+1;
    } while (idx != 0);
    
    sort(arr.begin(), arr.end());
    
    return to_string(arr[0]) + " " + to_string(arr[arr.size()-1]);
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0;i<n;i++){
        string s="";
        for(int j=0;j<n;j++){
            if(arr1[i]%2==0 && arr2[i]%2==0) s+=" ";
            else s+="#";
            arr1[i]/=2;
            arr2[i]/=2;
        }
        reverse(s.begin(), s.end());
        answer.push_back(s);
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<double,int> a, pair<double,int> b){
    if(a.first == b.first)
        return a.second < b.second;
    else 
        return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double,int> >rates;
    vector<int> buf;
    
    for(int i=1;i<=N;i++){
        int a=0,b=0;
        for(int j:stages){
            if(i<=j) a++;
            if(i==j) b++;
        }
        if(a==0 || (b==0&&a>0)) buf.push_back(i);
        else rates.push_back(make_pair((double)b/a,i));
    }
    sort(rates.begin(),rates.end(),compare);
    
    for(int i=0;i<rates.size();i++)
        answer.push_back(rates[i].second);
    
    for(int i=0;i<buf.size();i++)
        answer.push_back(buf[i]); 
    
    return answer;
}
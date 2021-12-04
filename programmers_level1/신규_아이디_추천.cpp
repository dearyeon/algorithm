#include <string>
#include <queue>
#include <iostream>
using namespace std;

string solution(string a) {
    string answer = "";
    queue<char> q;
    for(int i=0;i<a.length();i++){
        if(((int)a[i]>=65&&(int)a[i]<=90))
            q.push(a[i]+32);
        else if(((int)a[i]>=97 && (int)a[i]<=122) ||(((int)a[i]>=48 && (int)a[i]<=57)) || (int)a[i]==45 || (int)a[i]==95 || ((int)a[i]==46 && !q.empty() && q.back()!='.'))
            q.push(a[i]);
        
        if(q.size()>=15)
            break;
    }
    
    int size = q.size();
    if(q.back()=='.')
        size--;
    
    for(int i=0;i<size;i++) {
        answer +=q.front();
        q.pop();
    }
    
    if(answer.length()==0)
        answer="aaa";
    else if(answer.length()==1) {
        answer+=answer[0];
        answer+=answer[0];
    } else if(answer.length()==2)
        answer+=answer[1];
    
    return answer;
}
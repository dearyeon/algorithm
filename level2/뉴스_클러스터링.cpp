#include <string>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int solution(string str1, string str2) {
    int inter_count = 0, sum_count = 0;
    map<string, pair<int, int> > m;
    map<string, pair<int, int> >::iterator it;

    for(int i=0;i<str1.length()-1;i++) {
        str1[i] = toupper(str1[i]);
        str1[i+1] = toupper(str1[i+1]);
        if(str1[i]>='A' && str1[i]<='Z' && str1[i+1]>='A' && str1[i+1]<='Z')
            m[str1.substr(i,2)].first++;
    }
    
    for(int i=0;i<str2.length()-1;i++) {
        str2[i] = toupper(str2[i]);
        str2[i+1] = toupper(str2[i+1]);
        if(str2[i]>='A' && str2[i]<='Z' && str2[i+1]>='A' && str2[i+1]<='Z')
            m[str2.substr(i,2)].second++;
    }

    for(it=m.begin();it!=m.end();it++) {
        inter_count += min(it->second.first,it->second.second);
        sum_count += max(it->second.first,it->second.second);
    }
    
    return sum_count ? (double)inter_count/sum_count*65536 : 65536;
}
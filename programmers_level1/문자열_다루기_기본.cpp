#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool solution(string s) {
    for(int c:s)
        if(c<48 || c>57) return false;
    return s.length()==4 || s.length()==6 ? true : false;
}
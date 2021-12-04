#include <string>
#include <vector>
#include <iostream>
using namespace std;
int solution(string s) {
    while(1) {
        if(s.find("zero") < s.length())
            s.replace(s.find("zero"), 4, "0");
        else if(s.find("one") < s.length())
            s.replace(s.find("one"), 3, "1");
        else if(s.find("two") < s.length())
            s.replace(s.find("two"), 3, "2");
        else if(s.find("three") < s.length())
            s.replace(s.find("three"), 5, "3");
        else if(s.find("four") < s.length())
            s.replace(s.find("four"), 4, "4");
        else if(s.find("five") < s.length())
            s.replace(s.find("five"), 4, "5");
        else if(s.find("six") < s.length())
            s.replace(s.find("six"), 3, "6");
        else if(s.find("seven") < s.length())
            s.replace(s.find("seven"), 5, "7");
        else if(s.find("eight") < s.length())
            s.replace(s.find("eight"), 5, "8");
        else if(s.find("nine") < s.length())
            s.replace(s.find("nine"), 4, "9");
        else break;
    }
    return stoi(s);
}
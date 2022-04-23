#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isNumber(char c) {
    if(48 <= (int)c && (int)c <= 57) return true;
    return false;
}

bool cmp(string a, string b) {
    int a_idx = 0;
    int b_idx = 0;
    string a_head = "";
    string b_head = "";
    
    
    while(!isNumber(a[a_idx])) a_head += toupper(a[a_idx++]);
    while(!isNumber(b[b_idx])) b_head += toupper(b[b_idx++]);
    
    if(a_head == b_head) {
        string a_num = "";
        string b_num = "";
        while(isNumber(a[a_idx])) a_num += a[a_idx++];
        while(isNumber(b[b_idx])) b_num += b[b_idx++];
        
        return stoi(a_num) < stoi(b_num);
    }
    return a_head < b_head;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), cmp);
    return files;
}
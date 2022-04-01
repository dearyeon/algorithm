#include <string>
#include <vector>
#include <cmath>
using namespace std;

string conv(int n, int k) {
    string s = "";
    while(n > 0) {
        s = to_string(n % k) + s;
        n /= k;
    }
    return s;
}

bool isPrime(string s) {
    if(s == "" || s == "1") return false;
    long long n = stoll(s);
    for(int i=2; i<=sqrt(n); i++) {
        if(n%i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string s = conv(n, k);
    
    string buf = "";
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '0') {
            if(isPrime(buf)) answer++;
            buf = "";
        } else buf += s[i];
    }
    
    if(buf.length() && isPrime(buf)) answer++; 
    
    return answer;
}
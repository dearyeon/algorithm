#include <string>
#include <vector>
#include <set>
using namespace std;

int getNs(int N, int b) {
    string s = "";
    for(int i=0; i<b; i++)
        s += to_string(N);
    return stoi(s);
}

int solution(int N, int number) {
    if(N == number) return 1;
    
    vector<set<int> > v(9);
    
    for(int k=1; k<=8; k++) {
        v[k].insert(getNs(N,k));
        
        for(int i=1; i<k; i++) {
            for(int j=1; j<k; j++) {
                if(i + j != k) continue;
                
                for(int ii : v[i]) {
                    for(int jj : v[j]) {
                        v[k].insert(ii + jj);
                        if(ii - jj > 0) v[k].insert(ii - jj);
                        v[k].insert(ii * jj);
                        if(ii / jj > 0) v[k].insert(ii / jj);
                    }
                }

            }
        }
        if(v[k].find(number) != v[k].end()) return k;
    }
    return -1;
}
#include <iostream>
using namespace std;

int main() {
    string answer;
    int a[8];
    cin >> a[0];
    answer = a[0] == 1 ? "ascending" : a[0] == 8 ? "descending" : "mixed";
    for(int i=1;i<8;i++) {
        cin >> a[i];
        if(answer == "ascending" && a[i-1] + 1 != a[i]) 
            answer = "mixed";
        else if(answer == "descending" && a[i-1] - 1 != a[i]) 
            answer = "mixed";
    }
    return 0;
}
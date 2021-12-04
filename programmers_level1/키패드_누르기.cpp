#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cal(int x, int* arr){
    int r=0;
    arr[0]>x?r+=(arr[0]-x):r+=(x-arr[0]);
    arr[1]>1?r+=(arr[1]-1):r+=(1-arr[1]);
    return r;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int temp=0;
    int left[]={3,0};
    int right[]={3,2};
    while(numbers.size()-1>=temp){
        if(numbers[temp]==1||numbers[temp]==4||numbers[temp]==7){
            int x=(numbers[temp]-1)/3;
            left[0]=x,left[1]=0;
            answer+="L";
        } else if (numbers[temp]==3||numbers[temp]==6||numbers[temp]==9) {
            int x=numbers[temp]/3-1;
            right[0]=x,right[1]=2;
            answer+="R";
        } else if(numbers[temp]==2||numbers[temp]==5||numbers[temp]==8){
            int x=(numbers[temp]-2)/3;
            if(cal(x,left)<cal(x,right)) {
                left[0]=x,left[1]=1;
                answer+="L";
            } else if(cal(x,left)>cal(x,right)) {
                right[0]=x,right[1]=1;
                answer+="R";
            } else {
                if(hand=="left") {
                    left[0]=x,left[1]=1;
                    answer+="L";
                } else {
                    right[0]=x,right[1]=1;
                    answer+="R";
                }
            }
        } else if(numbers[temp]==0) {
            if(cal(3,left)<cal(3,right)) {
                left[0]=3,left[1]=1;
                answer+="L";
            } else if(cal(3,left)>cal(3,right)) {
                right[0]=3,right[1]=1;
                answer+="R";
            } else {
                if(hand=="left") {
                    left[0]=3,left[1]=1;
                    answer+="L";
                } else {
                    right[0]=3,right[1]=1;
                    answer+="R";
                }
            }
        }
        temp++;
    }
    return answer;
}
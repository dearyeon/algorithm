#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool s(int num){
    for(int i=2;i<=sqrt(num);i++){
        if(num%i == 0)
            return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    while(nums.size()>=3) {
        int temp = nums[0];
        nums.erase(nums.begin());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(s(temp+nums[i]+nums[j])==true)
                    answer++;
            }
        }
    }

    return answer;
}
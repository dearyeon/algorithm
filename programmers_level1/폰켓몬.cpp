#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solution(vector<int> nums) {
    int count = nums.size() / 2;
    
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    int nums_size = nums.size();
    
    return min(count, nums_size);
}
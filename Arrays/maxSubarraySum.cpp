#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubarraySum(vector<int> nums){
    int n = nums.size();
    int curr_sum = 0, max_sum = INT_MIN;
    for(int i=0; i<n; i++){
        curr_sum = max(nums[i], curr_sum+nums[i]);
        max_sum = max(curr_sum, max_sum);
    }
    return max_sum;
}

int main(){
    vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubarraySum(nums);
}
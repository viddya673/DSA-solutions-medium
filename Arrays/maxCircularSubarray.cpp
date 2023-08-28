#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minSum = INT_MAX, maxSum = INT_MIN;
        int currMin = 0, currMax = 0, total = 0;

        for(int num: nums){
            total += num;
            currMin = min(num, num+currMin);
            currMax = max(num, num+currMax);

            minSum = min(minSum, currMin);
            maxSum = max(maxSum, currMax);
        }
        if(total == minSum)
            return maxSum;

        return max(maxSum, total-minSum);
    }
};

int main(){
    Solution s;
    vector<int> nums{1,-2,3,-2};
    cout<<s.maxSubarraySumCircular(nums);
    return 0;
}
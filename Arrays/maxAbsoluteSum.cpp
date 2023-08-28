#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum = nums[0], curmax = nums[0];
        int minsum = nums[0], curmin = nums[0];
        for(int i=1; i<nums.size(); i++){
            curmax = max(nums[i], nums[i]+curmax);
            maxsum = max(maxsum, curmax);
            curmin = min(nums[i], nums[i]+curmin);
            minsum = min(minsum, curmin);
        }
        return max(abs(maxsum), abs(minsum));
    }
};

int main(){
    Solution s;
    vector<int> nums{2,-5,1,-4,3,-2};
    cout<<s.maxAbsoluteSum(nums);
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);

        for(int i=1; i<n+1; i++){
            if(i>1)
                dp[i] = max(dp[i-1], nums[i-1]+dp[i-2]);
            else
                dp[i] = max(nums[i-1], dp[i-1]);
        }
        return dp[n];
    }
};

int main(){
    vector<int> nums{2,7,9,3,1};
    Solution s;
    cout<<s.rob(nums);
    return 0;
}
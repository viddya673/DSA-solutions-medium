#include <iostream>
#include <vector>
using namespace std;

class Solution {
// Memoization
// private: 
//     int solve(int n, vector<int>& nums, vector<int>& dp){
//         if(n==0) return nums[0];

//         if(dp[n]!=-1) dp[n];

//         int pick = nums[n];
//         if(n>1)
//             pick += solve(n-2, nums, dp);
//         int dont_pick = solve(n-1, nums, dp);

//         return dp[n] = max(pick, dont_pick);
//     }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        dp[0] = nums[0];

        for(int i=1; i<n; i++){
            int rob = nums[i];
            if(i>1)
                rob += dp[i-2];
            int dont_rob = dp[i-1];
            dp[i] = max(rob, dont_rob);
        }
        return dp[n-1];
    }
};

int main(){
    vector<int> nums{2,7,9,3,1};
    Solution s;
    cout<<s.rob(nums);
    return 0;
}
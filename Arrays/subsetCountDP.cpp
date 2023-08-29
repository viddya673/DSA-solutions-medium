#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subsetCount(vector<int>& nums, int target) {
        int n=nums.size();
        int dp[n+1][target+1];

        for(int i=0; i<n+1; i++)
            dp[i][0] = 1;

        for(int i=1; i<target+1; i++)
            dp[0][i] = 0;

        for(int i=1; i<n+1; i++){
            for(int j=1; j<target+1; j++){
                if(j>=nums[i-1])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                if(j<nums[i-1])
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];
    }
};

int main(){
    vector<int> nums{2, 3, 5, 6, 8, 10};
    Solution s;
    cout<<s.subsetCount(nums, 10);
    return 0;
}
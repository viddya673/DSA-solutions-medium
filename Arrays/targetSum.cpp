/*Target Sum
let us say we have the array as [1,1,1,1,1] and the target = 3;
We just need to add (+ or -) signs in front of the integers.

e.g +1 +1 +1 -1 -1 = 3

Essentially, what we are doing is that we are just splitting the numbers into two subsets, one with positive signs and the other with negative signs

(1 , 1 , 1) => with positive signs
(1 , 1) => with negative signs

and we are calculating the difference of the sum of these two sets
(1 , 1 , 1) => with positive signs , sum = 3
(1 , 1) => with negative signs , sum = 2

diff = target = (3-2) = 1

So we just need to find all such pairs of subsets whose sum difference is equal to our given target.

Consider S1 and S2 to be one such pair then the following equations holds

S1 - S2 = target
S1 + S2 = sum of all the elements

By simplifing the above 2 equations we get, 2* S1 = target + Sum of all the elements

=> S1 = (target + Sum of all the elements) / 2

So, this problem now reduces to just finding count of subsets which are having sum equal to S1.*/

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
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];
    }

    int findTargetSumWays(vector<int>& nums, int target){
        int sum=0;
        for(int num: nums)
            sum+=num;

        if(abs(target)>sum || (sum+target)%2 != 0)
            return 0;

        int s1 = (sum+target)/2;
        return subsetCount(nums, s1);
    }
};

int main(){
    vector<int> nums{1,1,1,1,1};
    Solution s;
    cout<<s.findTargetSumWays(nums, 3);
}
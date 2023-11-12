#include <bits/stdc++.h>
#include <vector>
using namespace std;

//10 20 30 10.
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for(int i=1; i<n; i++){
        int one_jump = dp[i-1] + abs(heights[i]-heights[i-1]);
        int two_jumps = INT_MAX;
        if(i>1)
            two_jumps = dp[i-2] + abs(heights[i]-heights[i-2]);
        dp[i] = min(one_jump, two_jumps);
    }
    return dp[n-1];
}

int main(){
    vector<int> nums{7, 4, 4, 2, 6, 6, 3, 4};
    int n = nums.size();
    cout<<frogJump(n, nums);
}
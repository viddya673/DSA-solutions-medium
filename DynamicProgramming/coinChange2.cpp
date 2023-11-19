#include <iostream>
#include <vector>
using namespace std;

/* Memoization */
// long helper(int ind, int* denominations, int n, int value, vector<vector<long>>& dp){
//     if (ind == n) {
//         if (value == 0) return 1;
//         return 0;
//     }

//     if(dp[ind][value]!=-1) return dp[ind][value];

//     long take = 0;
//     if(value>=denominations[ind]){
//         value -= denominations[ind];
//         take = helper(ind, denominations, n, value, dp);
//         value += denominations[ind];
//     }

//     long not_take = helper(ind+1, denominations, n, value, dp);

//     return dp[ind][value] = (take + not_take);
// }

/* Tabulation */
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n+1, vector<long>(value+1));
    for(int i=0; i<=n; i++)
        dp[i][0] = 1;
    for(int i=1; i<=value; i++)
        dp[0][i] = 0;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=value; j++){
            long take=0;
            if(j>=denominations[i-1]){
                take = dp[i][j-denominations[i-1]];
            }
            long not_take = dp[i-1][j];
            dp[i][j] = take + not_take;
        }
    }

    return dp[n][value];
    // return helper(0, denominations, n, value, dp);
}

int main(){
    int nums[] = {1, 2, 3};
    cout<<countWaysToMakeChange(nums, 3, 4);
}
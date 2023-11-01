#include <vector>
#include <iostream>
using namespace std;

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        bool dp[n+1][sum+1];
        
        for(int i=1; i<sum+1; i++)
            dp[0][i] = false;
        
        for(int i=0; i<n+1; i++)
            dp[i][0] = true;
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(j<arr[i-1])
                    dp[i][j] = dp[i-1][j];
                if(j>=arr[i-1])
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
        return dp[n][sum];
    }
};

class Solution2{
    private: 
    bool helper(int n, int k, vector<int> &arr, vector<vector<int>>& dp){
        if(k==0)
            return true;
        if(n==0)
            return false;

        if(dp[n][k]!=-1) return dp[n][k];

        bool not_taken = helper(n-1, k, arr, dp);

        bool taken = false;
        if(arr[n-1]<=k)
            taken = helper(n-1, k-arr[n-1], arr, dp);

        return dp[n][k] = (taken || not_taken);
    }

    public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return helper(n, k, arr, dp);
    }
};

int main(){
    Solution2 s;
    vector<int> nums{3, 34, 4, 12, 5, 2};
    cout<<s.subsetSumToK(nums.size(), 11, nums);
    return 0;
}
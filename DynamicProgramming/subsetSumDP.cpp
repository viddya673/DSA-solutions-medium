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

int main(){
    Solution s;
    vector<int> nums{3, 34, 4, 12, 5, 2};
    cout<<s.isSubsetSum(nums, 30);
    return 0;
}
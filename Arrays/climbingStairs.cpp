#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n<=2) 
            return n;
        int prev = 1;
        int curr = 2;
        for(int i=3; i<n+1; i++){
            int sum = prev+curr;
            prev = curr;
            curr = sum;
        }
        return curr;
    }
};

// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n<=2) 
//             return n;
//         vector<int> dp(n+1);
//         dp[0]=0;
//         dp[1]=1;
//         dp[2]=2;
//         for(int i=3; i<n+1; i++){
//             dp[i] = dp[i-1]+dp[i-2];
//         }
//         return dp[n];
//     }
// };

int main(){
    Solution s;
    cout<<s.climbStairs(5);
    return 0;
}
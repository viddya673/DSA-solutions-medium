#include <iostream>
#include <vector>
using namespace std;

class Solution {\
/* Memoization */
// private:
//     int helper(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp){
//         if(ind1==s1.length() || ind2==s2.length())
//             return 0;
        
//         if(dp[ind1][ind2]!=-1)
//             return dp[ind1][ind2];
        
//         if(s1[ind1]==s2[ind2])
//             return dp[ind1][ind2] = 1 + helper(ind1+1, ind2+1, s1, s2, dp);
        
//         return dp[ind1][ind2] = max(helper(ind1+1, ind2, s1, s2, dp), helper(ind1, ind2+1, s1, s2, dp));
//     }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return helper(0, 0, text1, text2, dp);

        /* Tabulation */
        int dp[n+1][m+1];

        for(int i=0; i<m+1; i++)
            dp[0][i] = 0; 
        for(int i=0; i<n+1; i++)
            dp[i][0] = 0; 

        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};

int main(){
    Solution s;
    string text1 = "abcde";
    string text2 = "ace";
    cout<<s.longestCommonSubsequence(text1, text2);
}
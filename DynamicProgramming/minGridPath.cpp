#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
/* Memoization */
private: 
    int solver(int r, int c, vector<vector<int>> grid, vector<vector<int>>& dp) {
        if (r == grid.size() - 1 && c == grid[0].size() - 1)
            return grid[r][c];
            
        if (r == grid.size() || c == grid[0].size())
            return INT_MAX;
        
        if (dp[r][c] != -1)
            return dp[r][c];

        int down = solver(r + 1, c, grid, dp);
        int right = solver(r, c + 1, grid, dp);

        return dp[r][c] = grid[r][c] + min(right, down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        /* Tabulation */
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i==n-1 && j==m-1)
                    dp[i][j] = grid[i][j];
                else {
                    int right = INT_MAX, down = INT_MAX;
                    if(i<n-1) down = dp[i+1][j];
                    if(j<m-1) right = dp[i][j+1];
                    dp[i][j] = grid[i][j] + min(right, down);
                }
            }
        }
        return dp[0][0];
        // return solver(0, 0, grid, dp);
    }
};

int main(){
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };
    Solution s;
    cout<<s.minPathSum(matrix);
}
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int i, int j, vector<vector<char>> board, vector<vector<int>>& vis){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='O' || vis[i][j])
            return;
        else
            vis[i][j] = 1;

        dfs(i-1, j, board, vis);
        dfs(i, j-1, board, vis);
        dfs(i, j+1, board, vis);
        dfs(i+1, j, board, vis);
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(!vis[i][j])
                        dfs(i, j, board, vis);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};

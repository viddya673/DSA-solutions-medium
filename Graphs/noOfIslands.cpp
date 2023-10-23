#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void bfs(pair<int, int> start, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push(start);
        vis[start.first][start.second] = 1;

        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            vis[i][j] = 1;
            for (int k = 0; k < 4; k++) {
                int nrow = i + drow[k];
                int ncol = j + dcol[k];
                if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    bfs({i, j}, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }
};


int main(){
    vector<vector<char>> grid {{'1','1','0','0','0'},
                            {'1','1','0','0','0'},
                            {'0','0','1','0','0'},
                            {'0','0','0','1','1'}};
    Solution s;
    cout<<s.numIslands(grid);
}

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
    private: 
        void dfs(int row, int col, vector<vector<int>> grid, vector<vector<int>>& visited, vector<pair<int, int>>& temp, int row0, int col0){
            visited[row][col] = 1;
            temp.push_back({row-row0, col-col0});
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for(int i=0; i<4; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(ncol>=0 && ncol<grid[0].size() && nrow>=0 && nrow<grid.size() && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                    dfs(nrow, ncol, grid, visited, temp, row0, col0);
                }
            }
        }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        set<vector<pair<int, int>>> result;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j]==1){
                    vector<pair<int, int>> temp;
                    dfs(i, j, grid, visited, temp, i, j);
                    if(temp.size()>0) result.insert(temp);
                }
            }
        }
        return result.size();
    }
};

int main(){
    vector<vector<int>> grid = {{1, 1, 0, 1, 1},
                                {1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1},
                                {1, 1, 0, 1, 1}};
    Solution s;
    cout<<s.countDistinctIslands(grid);
}
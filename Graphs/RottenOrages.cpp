#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int fresh_count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({{i,j}, 0});
                }
                if(grid[i][j] == 1) fresh_count++;
            }
        }
        
        int rot_count=0, max_time=0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            pair<pair<int, int>, int> curr = q.front();
            q.pop();
            int r = curr.first.first;
            int c = curr.first.second;
            int t = curr.second;
            max_time = max(max_time, t); 
            
            for(int i=0; i<4; i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                 && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 1;
                    rot_count++;
                }
            }
        }
        return (fresh_count==rot_count) ? max_time : -1;
    }
};

int main(){
    vector<vector<int>> grid{{0,1,2}, {0,1,1}, {2,1,1}};
    Solution s;
    cout<<s.orangesRotting(grid);
}
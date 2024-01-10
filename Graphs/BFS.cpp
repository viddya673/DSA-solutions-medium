#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    queue<int> q;
    vector<int> visited(n+1, 0);
    vector<int> res;
    int root=0;
    q.push(root);
    visited[0] = 1;
    while(!q.empty()){
        int l_size = q.size();

        for(int i=0; i<l_size; i++){
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for(int a: adj[curr]){
                if(visited[a]==0){
                    visited[a]=1;
                    q.push(a);
                }
            }
        }
    }
    return res;
}

vector<int> bfsGridTraversal(int n, vector<vector<int>> adj){
    int grid[n][n] = {0};
    for(int i=0; i<n; i++){
        int u = i;
        for(int v: adj[i]){
            grid[u][v] = 1;
        }
    }

    queue<int> q;
    vector<int> vis(n, 0);
    vector<int> res;

    q.push(0);
    vis[0] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        res.push_back(u);

        for(int v=0; v<n; v++){
            if(grid[u][v]==1 && !vis[v]){
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    return res;
}

int main(){
    vector<vector<int>> adj{{1,3}, {0, 2}, {1, 5}, {0, 4}, {3, 6}, {2, 6, 7}, {4, 5}, {5}};
    int n = adj.size();
    vector<int> res = bfsGridTraversal(n, adj);
    for(int r: res){
        cout<<r<<endl;
    }
}
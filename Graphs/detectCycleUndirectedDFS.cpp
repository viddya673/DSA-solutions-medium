#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    private:
        bool dfs(int parent, int node, vector<vector<int>> adj, vector<int>& vis){
            vis[node] = 1;
            for(auto adjNode: adj[node]){
                if(!vis[adjNode]){
                    if(dfs(node, adjNode, adj, vis)==true)
                        return true;
                }
                else if(adjNode != parent)
                    return true;
            }
            return false;
        }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<vector<int>> adj) {
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(-1, i, adj, vis)==true)
                    return true;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int>> grid{{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    Solution s;
    cout<<s.isCycle(5, grid);
}
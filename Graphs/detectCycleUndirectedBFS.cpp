#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    private:
        bool isCycle(int start, vector<vector<int>> adj, vector<int>& vis){
            queue<pair<int, int>> q;
            q.push({-1, start});
            vis[start] = 1;
            
            while(!q.empty()){
                int node = q.front().second;
                int parent = q.front().first;
                q.pop();
                {
                    for(auto adjacent: adj[node]){
                        if(!vis[adjacent]){
                            q.push({node, adjacent});
                            vis[adjacent] = 1;
                        }else if(parent != adjacent){
                            return true;
                        }
                    }
                }
            }
            return false;
        }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<vector<int>> adj) {
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++){
            if(vis[i]==0){
                if(isCycle(i, adj, vis)==true)
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
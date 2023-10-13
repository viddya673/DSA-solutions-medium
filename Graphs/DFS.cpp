#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
        void dfs(int node, vector<int>& ls, vector<int>& vis, vector<vector<int>> adj){
            vis[node] = 1;
            ls.push_back(node);
            for(int a: adj[node]){
                if(!vis[a]){
                    dfs(a, ls, vis, adj);
                }
            }
        }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<vector<int>> adj) {
        int start = 0;
        vector<int> vis(V+1, 0);
        vector<int> ls;
        dfs(start, ls, vis, adj);
        
        return ls;
    }
};

int main(){
    Solution s;
    int V = 6;
    vector<vector<int>> adj{{2, 3, 1}, {0}, {0, 4}, {0}, {2, 5}, {4}};
    vector<int> res = s.dfsOfGraph(V, adj);
    for(int r: res){
        cout<<r<<endl;
    }
}
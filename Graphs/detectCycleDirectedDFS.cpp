#include <vector>
#include <iostream>
using namespace std;

class Solution {
  private:
    bool dfs(int src, vector<int> adj[], vector<int>& vis, vector<int>& pathVis){
        vis[src] = 1;
        pathVis[src] = 1;
        
        //Traversing adjacent nodes
        for(int adjNode: adj[src]){
            if(!vis[adjNode]){
                if(dfs(adjNode, adj, vis, pathVis)==true) 
                    return true;
            }
            else if(pathVis[adjNode]) return true;
        }
        
        pathVis[src] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i])
                if(dfs(i, adj, vis, pathVis)==true)
                    return true;
        }
        return false;
    }
};

void addEdge(vector < int > adj[], int u, int v) {
  adj[u].push_back(v);
}

int main() {

  int V = 6;

  vector < int > adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 5);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  addEdge(adj, 4, 0);
  addEdge(adj, 4, 1);
  

  Solution obj;
  if (obj.isCyclic(V, adj))
    cout << "Cycle Detected" << "\n";
  else
    cout << "No Cycle Detected";

  return 0;
}
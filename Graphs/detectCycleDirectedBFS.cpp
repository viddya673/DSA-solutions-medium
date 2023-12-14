#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    bool topologicalSort(int numCourses, vector<vector<int>> adj){
        vector<int> indegree(numCourses, 0);
        for(auto a: adj)
            for(int i: a)
                indegree[i]++;

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0) q.push(i);
        }
        int topo=0;
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            topo++;

            for(int n: adj[currNode]){
                indegree[n]--;
                if(indegree[n]==0) q.push(n);
            }
        }
        return (topo!=numCourses);
    }
public:
    bool detectCycleDirectedBFS(int V, vector<vector<int>> adj) {
        return topologicalSort(V, adj);
    }
};

void addEdge(vector<vector<int>>& adj, int u, int v) {
  adj[u].push_back(v);
}

int main() {

  int V = 6;

  vector <vector<int>> adj(V);
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 5);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  addEdge(adj, 4, 0);
  addEdge(adj, 4, 1);
  
  Solution obj;
  if (obj.detectCycleDirectedBFS(V, adj))
    cout << "Cycle Detected" << "\n";
  else
    cout << "No Cycle Detected";

  return 0;
}
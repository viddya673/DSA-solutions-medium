#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// n: number of nodes, m: number of edges
vector<vector<pair<int, int>>> createAdjMatrix(int n, int m, vector<pair<pair<int, int>, int>> &g){
    vector<vector<pair<int, int>>> adj(n+1);
    for(int i=0; i<m; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    return adj;
}

//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<pair<int, int>>> adj)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;

    vector<int> vis(V+1, 0);
    // {wt, node}
    pq.push({0, 1});
    int sum = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node] == 1) continue;
        // add it to the mst
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edW = it.second;
            if (!vis[adjNode]) {
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}

//Funtion to find the edges of the minimum spanning tree
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<vector<pair<int, int>>> adj = createAdjMatrix(n, m, g);
    vector<pair<pair<int, int>, int>> mst;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> visited(n+1, 0);
    pq.push(make_pair(0, make_pair(1, -1)));

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        if(visited[node]) continue;
        
        if(parent!=-1){
            mst.push_back({{parent, node}, wt});
            cout<<node<<"added"<<endl;
        } 
        visited[node] = 1;
        for(auto n: adj[node]){
            if(!visited[n.first]){
                pq.push(make_pair(n.second, make_pair(n.first, node)));
            }
        }
    }
    return mst;
}

int main(){
    vector<pair<pair<int, int>, int>> graph{
        {{1, 2}, 2},
        {{1, 4}, 6},
        {{2, 1}, 2},
        {{2, 3}, 3},
        {{2, 4}, 8},
        {{2, 5}, 5},
        {{3, 2}, 3},
        {{3, 5}, 7},
        {{4, 1}, 6},
        {{4, 2}, 8},
        {{4, 5}, 9},
        {{5, 2}, 5},
        {{5, 3}, 7},
        {{5, 4}, 9}
    };
    vector<vector<pair<int, int>>> adj = createAdjMatrix(5, 14, graph);
    int MinSum = spanningTree(5, adj);
    vector<pair<pair<int, int>, int>> result = calculatePrimsMST(5, 14, graph);
    for (auto edge : result)
    {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << "\n";
    }
    cout<<"Minimum sum:"<<MinSum<<endl;
    return 0;
}
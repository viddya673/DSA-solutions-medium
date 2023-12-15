#include <stack>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> createAdj(int n, vector<vector<int>> edges){
    vector<vector<int>> adj(n);
    for(auto edge: edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }
    return adj;
}

vector<vector<int>> createReverseAdj(int n, vector<vector<int>> edges){
    vector<vector<int>> adj(n);
    for(auto edge: edges){
        int u = edge[0];
        int v = edge[1];
        adj[v].push_back(u);
    }
    return adj;
}

void dfs(int src, vector<vector<int>> adj, stack<int>& stk, vector<int>& vis){
    vis[src] = 1;
    for(int n: adj[src]){
        if(!vis[n]){
            dfs(n, adj, stk, vis);
        }
    }
    stk.push(src);
}

void dfs2(int src, vector<vector<int>> adj, vector<int>& vis, vector<int>& temp){
    vis[src] = 1;
    temp.push_back(src);
    for(int n: adj[src]){
        if(!vis[n]){
            dfs2(n, adj, vis, temp);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj = createAdj(n, edges);
    vector<int> vis(n, 0);
    stack<int> stk;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, adj, stk, vis);
        }
    }
    vector<vector<int>> scc;
    vector<vector<int>> revAdj = createReverseAdj(n, edges);
    fill(vis.begin(), vis.end(), 0);

    while(!stk.empty()){
        int src = stk.top();
        stk.pop();
        vector<int> temp;
        if(!vis[src]){
            // scc++ : to just count the number of connected components
            dfs2(src, revAdj, vis, temp);
            scc.push_back(temp);
        }
    }
    return scc;
}

int main(){
    vector<vector<int>> edges{
        {5, 6},
        {0, 1},
        {1, 2},
        {1, 4},
        {2, 3},
        {3, 2},
        {4, 0},
    };
    vector<vector<int>> result = stronglyConnectedComponents(7, edges);
    for(auto item: result){
        for(int i: item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
    private:
    void topologicalSortDfs(int src, vector<int> adj[], vector<int>& vis, stack<int>& stk){
        vis[src]=1;
        for(int n: adj[src]){
            if(!vis[n]){
                topologicalSortDfs(n, adj, vis, stk);
            }
        }
        stk.push(src);
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> st;
        vector < int > vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
              topologicalSortDfs(i, adj, vis, st);
            }
        }
        vector < int > topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
         }
         return topo;
	}
};

int main(){
    vector<int> adj[6];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[3].push_back(1);
    adj[2].push_back(3);

    Solution obj;
    vector<int> v=obj.topoSort(6, adj);
    for(auto it:v)
        cout<<it<<" ";
    return 0;
}
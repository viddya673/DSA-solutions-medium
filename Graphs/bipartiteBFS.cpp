#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
private:
    bool bfs(int start, vector<int> adj[], vector<int>& colored){
        queue<int> q;
        q.push(start);
        colored[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int adjNode: adj[node]){
                if(colored[adjNode]==-1){
                    colored[adjNode] = !colored[node];
                    q.push(adjNode);
                }
                else if(colored[adjNode]==colored[node])
                    return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> colored(V, -1);
	    for(int i=0; i<V; i++){
            if(colored[i]==-1){
                if(!bfs(i, adj, colored)) return false;
            }
        }
	    return true;
	}
};

int main(){
    vector<int> adj[] = {{1}, {2, 5}, {1, 3}, {2, 4, 6, 7}, {3, 5}, {1, 4}, {3, 7}, {6}};
    int V = 8;
    Solution s;
    cout<<s.isBipartite(V, adj);
}
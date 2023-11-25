#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    bool dfs(int start, int color, vector<int> adj[], vector<int>& colored){
        colored[start] = color;
        for(int adjNode: adj[start]){
            if(colored[adjNode]==-1){
                if (!dfs(adjNode, !colored[start], adj, colored))
                    return false;
            }else if(colored[adjNode]==color)
                return false;
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> colored(V, -1);
	    for(int i=0; i<V; i++){
            if(colored[i]==-1){
                colored[i] = 0;
                if(!dfs(i, 0, adj, colored)) return false;
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
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
    
        for(int i=0; i<V; i++){
            for(auto edge: edges){
                if(dist[edge[0]]!=1e8 && dist[edge[0]]+edge[2] < dist[edge[1]])
                    dist[edge[1]] = dist[edge[0]]+edge[2];
            }
        }
    
        //checking for a negative cycle
        for(auto edge: edges){
            if(dist[edge[0]]!=1e8 && dist[edge[0]]+edge[2] < dist[edge[1]]){
                return {-1};
            }
        }
        return dist;
    }
};

int main() {

	int V = 6;
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};

	int S = 0;
	Solution obj;
	vector<int> dist = obj.bellman_ford(V, edges, S);
	for (auto d : dist) {
		cout << d << " ";
	}
	cout << endl;

	return 0;
}
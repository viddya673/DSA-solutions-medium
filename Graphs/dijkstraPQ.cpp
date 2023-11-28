#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
    private: 
    void dijstraTrav(int s, int v, vector<vector<int>> adj[], vector<int>& dist){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, s});
        
        while(!minHeap.empty()){
            pair<int, int> curr = minHeap.top();
            minHeap.pop();
            int curr_node = curr.second;
            int curr_dist = curr.first;
            
            for(auto vect_node: adj[curr_node]){
                int next_node = vect_node[0];
                int node_dist = vect_node[1];
                if(dist[next_node] > curr_dist+node_dist){
                    dist[next_node] = curr_dist+node_dist;
                    minHeap.push({dist[next_node], next_node});
                }
            }
        }
    }
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        dijstraTrav(S, V, adj, dist);
        return dist;
    }
};

int main(){
    Solution s;
    vector<vector<int>> adj[] = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
    vector<int> dist = s.dijkstra(3, adj, 2);
    for(int d: dist)
        cout<<d<<endl;
}
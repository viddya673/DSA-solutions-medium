#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    private: vector<int> size, parent;
    public:
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1, 1);
            for(int i=1; i<=n; i++){
                parent[i]=i;
            }
        }
        int findUParent(int node){
            if(node==parent[node])
                return node;
            return parent[node] = findUParent(parent[node]);
        }
        void unionBySize(int u, int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u==ulp_v)
                return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

int kruskalMST(int n, vector<vector<int>> &edges)
{
	vector<pair<int, pair<int, int>>> adj;
	for(auto edge: edges){
		int u = edge[0];
		int v = edge[1];
		int wt = edge[2];
		adj.push_back({wt, {u, v}});
	}
	sort(adj.begin(), adj.end());

	DisjointSet ds(n);
	int mst = 0;
	for(auto edge: adj){
		int wt = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;

		if(ds.findUParent(u)!=ds.findUParent(v)){
			mst += wt;
			ds.unionBySize(u, v);
		}
	}
	return mst;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    int mstWt = kruskalMST(V, edges);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}
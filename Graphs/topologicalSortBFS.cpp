#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            for(int it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        vector<int> result;
        for(int i=0; i<V; i++)
            if(indegree[i]==0){
                q.push(i);
            }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            result.push_back(curr);
            for(int n: adj[curr]){
                indegree[n]--;
                if(indegree[n]==0) q.push(n);
            }
        }
        return result;
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